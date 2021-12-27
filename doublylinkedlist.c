//doubly linked list insertion/ deletion/ traversal

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

void insertathead(int x);
Node* getnewnode(int x);
void deletenode(int x);
void printnodefront();
void printnodereverse();

struct Node* head = NULL;

int main(){
    int length, value, index;
    printf("Enter the length of your list: \n");
    scanf("%d",  &length);

    for (int i=0; i<length; i++){
        printf("Enter data of node at index %d:\n", length-i-1);
        scanf("%d", &value);
        insertathead(value);
    }
    printf("Printing nodes\n");
    printnodefront();
    printf("\n");
    printnodereverse();
    printf("\n");

    printf("Delete node at index: \n");
    scanf("%d", &index);
    deletenode(index);

    printnodefront();


}

Node* getnewnode(int x){
    Node* temp1 = (Node*) malloc(sizeof(Node));
    temp1->data = x;
    temp1->next=NULL;
    temp1->next =NULL;
    return temp1;
}

void insertathead(int x){

    if (head==NULL){
        Node* temp1 = getnewnode(x);
        head = temp1;
        return;
    }

    Node* temp1 = getnewnode(x);
    temp1->next = head;
    head->prev = temp1;
    head = temp1;
}

void deletenode(int x){
    Node* temp1 = head;
    if (x==0){
        head = temp1->next;
        free(temp1);
        return;
    }

    for (int i=0; i<x-1; i++){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp1->next->next;
    free(temp2);
}

void printnodefront(){
    Node* temp1 = head;
    while(temp1 != NULL){
        printf("%d", temp1->data);
        temp1 = temp1->next;
    }
}

void printnodereverse(){
    Node* temp1 =  head;
    while (temp1->next != NULL){
        temp1 = temp1->next;
    }

    while (temp1 != NULL){
        printf("%d", temp1->data);
        temp1 = temp1->prev;
    }
}