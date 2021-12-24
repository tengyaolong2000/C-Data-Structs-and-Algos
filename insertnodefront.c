//build linked list from front by insertion

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

void insertnode(int x);
void printnode(Node* head);

Node* head = NULL;

int main(){
    int n, x;
    printf("Enter the length of your linked list: ");
    scanf("%d", &n);

    printf("Enter node values: ");
    for (int i=0; i<n; i++){
        scanf("%d", &x);
        insertnode(x);
        printnode(head);
    }

}

void insertnode(int x){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void printnode(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}