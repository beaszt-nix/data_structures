#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int val;
	struct node *left, *right;
	int height;
	int freq;
} node;

int max(int a, int b){
	return a>b?a:b;
}

int height(node *a){
	if (a == NULL)
		return 0;
	else{
		a->height = 1 + max(height(a->left), height(a->right));
		return a->height;
	}
}
int bal_fact(node *a){
	int bf;
	if (a->left == NULL)
		bf=0;
	else
		bf = a->left->height;
	if (a->right != NULL)
		bf -= a->right->height;
	return bf;
}

node *leftRotate(node *a){
	node *temp = a->right;
	a->right = temp->left;
	temp->left = a;
	return temp;
}

node *rightRotate(node *a){
	node *temp = a->left;
	a->left = temp->right;
	temp->right = a;
	return temp;
}
node *balance(node *a){
	if (a == NULL)
		return NULL;
	int bf = bal_fact(a);
	if (bf == 2){
		int bf1 = bal_fact(a->left);
		if (bf1 == -1)
			a->left = leftRotate(a->left);
		a = rightRotate(a);
	}
	else if (bf == -2){
		int bf1 = bal_fact(a->right);
		if (bf1 == 1)
			a->right = rightRotate(a->right);
		a = leftRotate(a);
	}
	return a;
}
node * insert(node *a, int val){
	if (a == NULL){
		a = (node *)malloc(sizeof(node));
		a->val = val;
		a->left = NULL;
		a->right = NULL;
		a->height =1;
		a->freq = 1;
		return a;
	}
	int l = 0, r = 0;
	if (a->left != NULL)
		l = a->left->height;
	if (a->right != NULL)
		r = a->right->height;
	a->height = 1 + max(l, r);
	if (a->val < val){
		a->right = insert(a->right, val);
		a->right = balance(a->right);
	}
	else if (a->val > val){
		a->left = insert(a->left, val);
		a->left = balance(a->left);
	}
	return a;
}

void inorder(node *a){
	if (a == NULL)
		return;
	inorder(a->left);
	printf("%d ", a->val);
	inorder(a->right);
}

node *lowest(node *a){
	node *cur = a, *pred = NULL;
	while (cur != NULL){
		pred = cur;
		if (cur->left == NULL)
			cur = cur->right;
		else
			cur = cur->left;
	}
	return pred;
}

node *highest(node *a){
	node *cur = a, *pred = NULL;
	while (cur != NULL){
		pred = cur;
		if (cur->right == NULL)
			cur=cur->left;
		else
			cur = cur->right;
	}
	return pred;
}
node * search(node *a, int val){
	if (a->val == val || a == NULL)
		return a;
	if (a->val < val)
		return search(a->right, val);
	else
		return search(a->left, val);
}

node* delete(node *a, int val){
	if (a == NULL)
		return a;
	if (a->val < val)
		a->right = delete(a->right, val);
	else if (a->val > val)
		a->left = delete(a->left, val);
	else{
		if (a->left == NULL){
			node *temp = a->right;
			free(a);
			return temp;
		}
		else if (a->right == NULL){
			node *temp = a->left;
			free(a);
			return temp;
		}
		
		node *next = lowest(a->right);
		a->val = next->val;
		a->right = delete(a->right, next->val);
	}
	return a;

}

int main(){
	clock_t t=clock();
	int n;
	scanf("%d", &n);
	node *root = NULL;
	for (int i = 1; i <= n; i++){
		root = insert(root, i);
	}
	t = clock()-t;
	printf("%d\n", height(root));
	printf("%lf is time taken\n", ((double)t)/CLOCKS_PER_SEC);
}
