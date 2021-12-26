//print linked list recursively from front and back

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void printlist(Node* node);
void printlistreverse(Node* node);
void buildlist();

Node* head = NULL;
int main(){
    buildlist();
    printf("Print linked list from front to back:\n");
    printlist(head);
    printf("\n");
    printf("Print linked list from back to front:\n");
    printlistreverse(head);

}

void buildlist(){
    int length, d;

    printf("Enter the length of your linked list: \n");
    scanf("%d", &length);
    printf("Enter the data at index 0:\n");
    scanf("%d", &d);
    Node* temp1 = (Node*) malloc(sizeof(Node));
    temp1->data=d;
    head = temp1;
    Node* temp2 = head;

    for(int i=0; i<length-1; i++){
        printf("Enter data of node at index %d: \n", i+1);
        scanf("%d", &d);
        temp1 = (Node*) malloc(sizeof(Node));
        temp1->data = d;
        temp2->next = temp1;
        temp2 = temp2->next;

    }
    temp2 = NULL;

}

void printlist(Node* node){
    if (node == NULL) return;
    printf("%d ", node->data);
    printlist(node->next);
}

void printlistreverse(Node* node){
    if (node == NULL) return;
    printlistreverse(node->next);
    printf("%d ", node->data);
}