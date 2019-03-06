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

node *ubound(node *a){
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

node *lbound(node *a){
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
	if (a->val == val || a==NULL)
		return a;
	if (a->val < val)
		return traverse(a->right, val);
	else
		return traverse(a->left, val);
}

void delete(node *a, int val){
	node *temp = traverse(a, val);
	if (height(a->left) < height(a->right)){
		node *repl = ubound(a->right);
		temp->val = repl->val;
		free(repl);
	}
	else{
		node *repl = lbound(a->left);
		temp->val = repl->val;
		free(repl);
	}
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
