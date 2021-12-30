#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void Enqueue(int x);
void Dequeue();
void printlist();

Node* head = NULL;
Node* tail = NULL;

int main(){
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Dequeue();
    printlist();
}

void Enqueue(int x){
    Node* temp1 = (Node*)  malloc(sizeof(Node));
    temp1->data = x;
    temp1->next = NULL;

    if (head == NULL && tail == NULL){
        head = tail = temp1;
    }

    tail->next = temp1;
    tail = temp1;
}

void Dequeue(){
    //note: no loops, all take constant time
    Node* temp = head;
    if (head == NULL) return;
    if (head == NULL && tail == NULL){
        head = tail = NULL;
    }
    else{
        head = temp->next;
    }
    free(temp);

}

void printlist(){
    Node* temp = head;
    while (temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
}