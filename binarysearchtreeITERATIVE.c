#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
}BstNode;

BstNode* Insert(BstNode* root, int data);
BstNode* generateNode(int data);
bool Search(BstNode* root, int data);

int main(){
    BstNode* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 15);
    root = Insert(root, 25);
    root = Insert(root, 17);
    root = Insert(root, 5);

    int searched;
    printf("Enter the data to be searched:\n");
    scanf("%d", &searched);
    

    if (Search(root, searched)) printf("Found it!\n");
    else printf("Not in tree :< \n");

}

BstNode* generateNode(int data){
    BstNode* temp = (BstNode*)malloc(sizeof(BstNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

BstNode* Insert(BstNode* root, int data){
    
    if (root == NULL) {
        root = generateNode(data);
        return root;
    }
    
    else{
        BstNode* temp = root;
        while (temp != NULL){
            if (data <= temp->data){
                if (temp->left == NULL) {
                    temp->left = generateNode(data);
                    return root;
                }
                temp = temp->left;
            }
            else {
                if (temp->right == NULL) {
                    temp->right = generateNode(data);
                    return root;
                }
                temp = temp->right;
        }
        
    }   
} 
}

bool Search(BstNode* root, int data){
    BstNode* temp = root;
    while(data != temp->data && temp!=NULL){
        if (data <= temp->data){
            if (temp->left==NULL) return false;
            temp = temp->left;
        }

        else {
            if (temp->right == NULL) return false;
            temp = temp->right;
        }
    }
    
   if (temp->data == data) return true;

    return false;
    

}



