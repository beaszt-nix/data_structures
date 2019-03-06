#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
	int val;
	struct node *left, *right;
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
node * insert(node *a, int val){
	if (a == NULL){
		a = (node *)malloc(sizeof(node));
		a->val = val;
		a->left = NULL;
		a->right = NULL;
		return a;
	}
	if (a->val < val)
		a->right = insert(a->right, val);
	else
		a->left = insert(a->left, val);
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
	int n;
	clock_t t = clock();
	scanf("%d", &n);
	node *root=NULL;
	for (int i = 1; i <= n; i++){
		root=insert(root, i);
	}
	printf("%d\n", height(root));
	t=clock()-t;
	printf("Time taken for execution: %lf\n", ((double)t)/CLOCKS_PER_SEC);
}
