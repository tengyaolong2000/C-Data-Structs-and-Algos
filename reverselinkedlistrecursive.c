//reverse linked list with recurison

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void buildlist();
void recursivereverse(Node* node);
void printlist(Node* node);

Node* head = NULL;

int main(){
    buildlist();
    printlist(head);
    recursivereverse(head);
    printf("\n");
    printlist(head);

}

void buildlist(){
    int length, data;
    Node* temp1 = (Node*) malloc(sizeof(Node));
    Node* temp2 = NULL;

    printf("Enter the length of your linked list: \n");
    scanf("%d", &length);

    printf("Enter the data of the node at index 0:\n");
    scanf("%d", &data);
    temp1->data=data;
    head = temp1;
    temp2 = temp1;

    for (int i=0; i<length-1;i++){
        temp1  =(Node*) malloc(sizeof(Node));
        printf("Enter the data of the node at index %d:\n", i+1);
        scanf("%d", &data);
        temp1->data = data;
        temp2->next =  temp1;
        temp2 = temp2->next;
    }
    temp2->next = NULL;
}

void printlist(Node* node){
    if (node == NULL) return;
    printf("%d ", node->data);
    printlist(node->next);
}

void recursivereverse(Node* node){
    
    if (node->next==NULL){
        head = node;
        return;
    }
    recursivereverse(node->next);
    
    /* 
    Node* noden = node->next;
    noden->next = node;
    node->next = NULL; 
    */
   //same as

   node->next->next = node;
   node->next->next->next = NULL;

}