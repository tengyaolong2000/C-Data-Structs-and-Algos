#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BstNode{
    int data;
    struct BstNode* right;
    struct BstNode* left;
}BstNode;

BstNode* Insert(BstNode* root, int data);
BstNode* generateNode(int data);
bool search(BstNode* root, int searched);

int main(){

    BstNode* root = NULL;
    root = Insert(root, 8);
    root = Insert(root,20);
    root = Insert(root,12);
    root = Insert(root,10);
    root = Insert(root,25);
    root = Insert(root,15);

    int searched;
    printf("Enter a number to be searched:\n");
    scanf("%d", &searched);


    if (search(root, searched)) printf("Node is in tree!");
    else printf("Node is not in tree :(\n");

}

BstNode* generateNode(int data){
    BstNode* node = (BstNode*) malloc(sizeof(BstNode));
    node->data = data;
    node->left = NULL;
    node->right =NULL;
    return node;  
}

//recursive method
BstNode* Insert(BstNode* root, int data){
    if (root == NULL) {
        root = generateNode(data);
    }

    else if (root->data >= data){
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    
    return root;
}

bool search(BstNode* root, int searched){
    if (root == NULL) return false;
    if (root->data == searched){
        return true;
    }
    else if (root->data >= searched){
        return search(root->left, searched);
    }

    else return search(root->right, searched);
}

