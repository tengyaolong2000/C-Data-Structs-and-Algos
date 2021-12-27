//linked list implementation of stack

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node;

void push(int x);
void pop();
void printstack(Node* node);

Node* top = NULL;

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    
    printstack(top);

}

void push(int x){
    Node* temp1 = (Node*) malloc(sizeof(Node));
    temp1->value = x;
    temp1->next = top;
    top = temp1;
}

void pop(){
    if (top == NULL) return;
    Node* temp1 = top;
    top = top->next;
    free (temp1);
}

void printstack(Node* node){
    if (node == NULL) return;
    printf("%d ", node->value);
    printstack(node->next);

}

