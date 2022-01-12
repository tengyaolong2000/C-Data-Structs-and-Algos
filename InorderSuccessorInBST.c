#include <stdio.h>
#include <stdlib.h>

typedef struct bstnode{
    int val;
    struct bstnode* left;
    struct bstmode* right;
}bstnode;

bstnode* generateNode(int value);
bstnode* Insert(bstnode* root, int data);
bstnode* Successor(bstnode* root, int data);
bstnode* findMin(bstnode* root);

int main(){
    bstnode* root = NULL;
    bstnode* successor = NULL;
    root = Insert(root, 12);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 13);
    root = Insert(root, 17);
    root = Insert(root, 1);
    root = Insert(root, 9);
    root = Insert(root, 14);
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 11);
    root = Insert(root, 18);

    successor = Successor(root, 14);
    printf("%d", successor->val);


}

bstnode* findMin(bstnode* root){
    if (root == NULL) return NULL;
    while(root->left!=NULL){
        root = root->left;
    }

    return root;
}

bstnode* generateNode(int value){
    bstnode* node = (bstnode*) malloc(sizeof(bstnode));
    node->val = value;
    node->left = NULL;
    node->right =NULL;

    return node;
}

bstnode* search(bstnode* root, int data){
    if (root == NULL) return NULL;
    if (root->val == data) return root;
    else if (data <= root->val){
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

bstnode* Insert(bstnode* root, int data){
    if (root == NULL){
        root = generateNode(data);
    }

    else if (data <= root->val) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);

    return root;
}

bstnode* Successor(bstnode* root, int data){

    //search the node O(h) where h is the height of the tree

    bstnode* current = search(root, data);
    if (current==NULL)  return NULL; //node does not exist

    //case 1: has right subtree
    if (current->right != NULL){
        return findMin(current->right);
    }

    else{ //no right subtree
        bstnode* successor = NULL;
        bstnode* ancestor = root;

        while(current != ancestor){
            if (current->val < ancestor->val){
                successor = ancestor;
                ancestor = ancestor->left;
            }

            else{ //current node lies in right, just need to go right
                ancestor = ancestor->right;
            }
        }

    return successor;
    }


}


