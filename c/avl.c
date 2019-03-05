#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *left, *right;
	int height;
} node;

int max(int a, int b){
	return a>b?a:b;
}

int height(node *a){
	if (a == NULL)
		return 0;
	else
		return 1 + max(height(a->left), height(a->right)); 
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

void update(node *a){
	if (a == NULL)
		return;
	a->height = height(a);
	update(a->left);
	update(a->right);
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
		return a;
	}
	if (a->val < val){
		a->right = balance(a->right);
		a->right = insert(a->right, val);
	}
	else{
		a->left = balance(a->left);
		a->left = insert(a->left, val); 
	}
	update(a);
	return a;
}

void preorder(node *a){
	if (a == NULL)
		return;
	preorder(a->left);
	printf("%d ", a->val);
	preorder(a->right);
}

node *highest(node *a){
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

node *lowest(node *a){
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
node * traverse(node *a, int val){
	if (a->val == val || a == NULL)
		return a;
	if (a->val < val)
		return traverse(a->right, val);
	else
		return traverse(a->left, val);
}

void delete(node *a, int val){
	node *temp = traverse(a, val);
	if (height(a->left) < height(a->right)){
		node *repl = lowest(a->right);
		temp->val = repl->val;
		free(repl);
	}
	else{
		node *repl = highest(a->left);
		temp->val = repl->val;
		free(repl);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	node *root = NULL;
	for (int i = 1; i <= n; i++){
		root = insert(root, i);
	}
	preorder(root);
	printf("\n");
}
