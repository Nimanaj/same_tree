#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* new_tree(int value) {
	Node* result = malloc(sizeof(Node));
	
	if(result != NULL) {
		result->left = NULL;
		result->right = NULL;
		result->value = value;
	}
	return result;
}

void print_tabs(int num) {
	for(int i = 0; i < num; i++) {
		printf("\t");
	}
}

void print_tree(Node* root, int lv) {	
	if(root == NULL) {
		print_tabs(lv);
	printf("[NULL]\n");
		return;
	}
	print_tabs(lv);
	printf("[%d]\n", root->value);
	print_tabs(lv);
	printf("left\n");
	
	print_tree(root->left, lv + 1);
	print_tabs(lv);
	printf("right\n");
	
	print_tree(root->right, lv + 1);
	print_tabs(lv);
	
}
 
bool same_tree(Node* p, Node* q){
	
	if (p == NULL && q == NULL) {
        return true;
    } else if (p == NULL || q == NULL) {
        return false;
    }

	if(p->value == q->value){
		same_tree(p->left, q->left);
		same_tree(p->right, q->right);
	} else {
		return false;
	}
}

void test_equals_bool(bool result, bool expected, int line){
	if(result == expected){
		printf("Test pass.\n");
	} else {
		printf("The test faild in line: [%d].\n", line);
	}
}

void test(){
	Node* n1 = new_tree(10);
	Node* n2 = new_tree(11);
	Node* n3 = new_tree(12);
	Node* n4 = new_tree(13);
	Node* n5 = new_tree(14);
	
	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;
	
	
	Node* m1 = new_tree(10);
	Node* m2 = new_tree(11);
	Node* m3 = new_tree(12);
	Node* m4 = new_tree(13);
	
	m1->left = m2;
	m1->right = m3;
	m3->left = m4;
	
	test_equals_bool(same_tree(n1, n1), true, __LINE__);
	test_equals_bool(same_tree(n1, m1), false, __LINE__);
	
	print_tree(n1, 0);
	printf("\n");
	printf("\n");
	printf("\n");
	print_tree(m1, 0);
	
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	
	free(m1);
	free(m2);
	free(m3);
	free(m4);
}

int main(){
	test();
}