#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void postorder(struct Node* root){
	if(root != NULL){
		postorder(root->right);
		postorder(root->left);
		printf("%d ",root->data);
	}
}

void search(struct Node* root,int key){
	if(root == NULL){
		return;
	} 
	
     if(root->data == key){
     	printf("%d has found at root",root->data);
	 }	else if(root->left->data == key){
	 	printf("%d has found at left side",key);
	 } else if(root->right->data == key){
	 	printf("%d has found at right side",key);
	 }
}

int main() {
    struct Node* root = createNode(100);
    root->left = createNode(50);
    root->right = createNode(105);

    root->left->left = createNode(40);
    root->left->right = createNode(60);

    root->right->right = createNode(106);

    root->right->left = createNode(101);
 
   

    printf("Preorder Traversal:\n");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\nTraverse: ");
    search(root,101);
    return 0;
}

