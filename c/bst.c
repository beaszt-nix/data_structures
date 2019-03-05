#include <stdio.h>
#include <stdlib.h>

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
void insert(node *a, int val){
	node *pred = NULL, *cur = a;
	while (cur != NULL){
		pred = cur;
		if (cur->val < val)
			cur = cur->right;
		else
			cur = cur->left;
	}
	if (pred->val < val){
		pred->right = (node *)malloc(sizeof(node));
		pred = pred->right;
	}
	else{
		pred->left = (node *)malloc(sizeof(node));
		pred = pred->left;
	}
	pred->val = val;
	pred->left = NULL;
	pred->right = NULL;
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
	scanf("%d", &n);
	node *root = (node *)malloc(sizeof(node));
	scanf("%d", &(root->val));
	root->left = NULL;
	root->right = NULL;
	for (int i = 0; i < n-1; i++){
		int temp;
		scanf("%d", &temp);
		insert(root, temp);
	}
	inorder(root);
	printf("\n");
	printf("%d\n", height(root));
}
