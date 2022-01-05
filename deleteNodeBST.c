#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;

Node* generateNode(int data);
Node* Insert(Node* root, int data);
void printTree(Node* root); //preorder
Node* DeleteNode(Node* root, int data);
Node* minValueNode(Node* node);

int main(){

    Node* root = NULL;

    root = Insert(root,12);
    root = Insert(root,5);
    root = Insert(root,15);
    root = Insert(root,3);
    root = Insert(root,7);
    root = Insert(root,13);
    root = Insert(root,17);
    root = Insert(root,1);
    root = Insert(root,9);
    root = Insert(root,14);
    root = Insert(root,20);
    root = Insert(root,8);
    root = Insert(root,11);
    root = Insert(root,18);
   


    printTree(root);
    printf("\n");
    DeleteNode(root, 15);
    printTree(root);


}

Node* generateNode(int data){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->val = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* Insert(Node* root, int data){
    if (root == NULL) root = generateNode(data);

    else if (data <= root->val){
        root->left = Insert(root->left, data);
    }

    else if (data >= root->val){
        root->right = Insert(root->right, data);
    }

    return root;

}

//preorder
void printTree(Node* root){
    if (root==NULL) return;
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

Node* DeleteNode(Node* node, int data){
    if(node == NULL) return node;

    else if (data < node->val) node->left = DeleteNode(node->left, data);
    else if (data > node->val) node->right = DeleteNode(node->right, data);

    else{ //found you little fuck, prepare to be deleted

        if (node->left == NULL && node->right == NULL){ //no backup, you die
            free(node);
            node = NULL;
        }
        else if (node->left == NULL){
            Node* temp = node;
            node = node->right;
            free(temp);   
        }
        else if (node->right == NULL){
            Node* temp = node;
            node = node->left;
            free(temp);
        }

        else{
            Node* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = DeleteNode(node->right, temp->val); //delete duplicate
        }


    }

    return node;

}


Node* minValueNode(Node* node){
    Node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}