//reverse linked list with array based stack

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* A[MAX_SIZE];
int top = -1;

Node* head = NULL;
void buildlinkedlist();
void printlist();

void pop();
void push(Node* node);


int main(){
    
    buildlinkedlist();
    Node* node1 = head;
    printf("Reversing linked list\n");
    while (node1 != NULL){
        push(node1);
        node1 = node1->next;
    }

    printlist();
    Node *temp1 = A[top];
    head = temp1;
    pop();
    

    while (top != -1){
        temp1->next = A[top];
        pop();
        temp1 = temp1->next;

    }
    temp1->next=NULL;

    printlist();


}

void buildlinkedlist(){
    int length, data;

    Node* temp1 = (Node*)malloc(sizeof(Node));
    printf("Enter the length of the linked list:\n");
    scanf("%d", &length);

    printf("Enter the data of the node at 0 index:\n");
    scanf("%d", &data);
    temp1->value = data;
    head = temp1;

    Node* temp2 = temp1;

    for (int i=0; i<length-1; i++){

        temp1 = (Node*) malloc(sizeof(Node));
        printf("Enter the data of the node at %d index:\n", i+1);
        scanf("%d", &data);
        temp1->value = data;
        temp2->next = temp1;
        temp2 = temp2->next;

    }
    temp2->next = NULL;

}

void pop(){
    if (top == -1){
        printf("Empty stack");
        return;
    }

    --top;
}
void push(Node* node){
    if (top == MAX_SIZE-1){
        printf("Error StackOverflow\n");
    }
    A[++top] = node;
}


void printlist(){
    Node* temp1 = head;
    while(temp1 != NULL){
        printf("%d ", temp1->value);
        temp1 = temp1->next;
    }
    printf("\n");
}