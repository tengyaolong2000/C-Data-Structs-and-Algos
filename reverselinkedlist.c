#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* reverselinkedlist();
void buildlist(int length);

Node* head = NULL;

int main(){
    int n;
    Node* printer;
    printf("Enter the length of you linked list: \n");
    scanf("%d", &n);
    buildlist(n);
    printer = head;
    while (printer != NULL){
        printf("%d ", printer->data);
        printer = printer->next;
    }
    printf("\n");

    printer = reverselinkedlist();
    while (printer != NULL){
        printf("%d ", printer->data);
        printer = printer->next;
    }


}

void buildlist(int length){
    Node* temp1 = (Node*) malloc(sizeof(Node));
    Node* temp2 = NULL;
    int n;
    printf("Enter data of node at index 0: \n");
    scanf("%d", &n);

    temp1->data=n;
    head = temp1;
    temp2 = head;

    for (int i=0; i<length-1; i++){
        temp1 = (Node*) malloc(sizeof(Node));
        printf("Enter data of node at index %d: \n", i+1);
        scanf("%d", &n);
        temp1->data = n;
        temp2->next = temp1;
        temp2 = temp2->next;
        
    }
    temp2 = NULL;
    

 }

 Node* reverselinkedlist(){

     Node *current, *previous, *head1;
     head1 = head;
     current = head1;
     previous = NULL;
     while (current !=NULL){
         head1 = head1->next;
         current->next = previous;
         previous = current;
         current = head1;
     }

     return previous;

 }