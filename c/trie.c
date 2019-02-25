#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	struct node* children[26] = { NULL };
	char val;
	int isEnd;
} node;

void trie_init(node *a){
	a->val = '\0';
	a->isEnd = 0;
}

void insert(node *a, char *b){
	node *current = a;
	for (int i = 0; i < strlen(b); i++){
		if (current->children[b[i]-'a'] == NULL){
			current->children[b[i]-'a'] = (node *)malloc(sizeof(node));
			current->children[b[i]-'a']->val = b[i];
		}
		current = current->children[b[i]-'a'];
	}
	current->isEnd = 1;
}
