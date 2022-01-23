//insert node at front, insert node at specified index, delete node and //////printnode 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;    
}Node;

void insertnode(int n, int data);
void insertnodefront(int n);
void deletenode(int n);
void printnode(Node* head);

Node* head = NULL;

int main(){
    printf("build your linked list: ");
    int x,n;
    printf("Enter the amount of nodes: ");
    scanf("%d", &x);
    for(int i=0; i<x; i++){
        printf("Enter the value: ");
        scanf("%d", &n);
        insertnodefront(n);
        printnode(head);
    }
    printf("Insert a node: Enter index and value: ");
    int t, y;
    scanf("%d %d", &t, &y);
    insertnode(t+1, y);
    printnode(head);

    printf("Delete node at index you enter: ");
    int h;
    scanf("%d", &h);
    deletenode(h+1);
    printnode(head);

    
}

void insertnodefront(int x){
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insertnode(int n, int data){
    Node* temp1 = (Node*) malloc(sizeof(Node));
    temp1->data = data;
    
    if (n==1){
        temp1->next= head;
        head = temp1;
        return;
    }

    Node* temp2 = head;
    for (int i=0; i<n-2;i++){
        temp2 = temp2->next;
        
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void deletenode(int n){
    Node* temp1 = head;
    for (int i=0; i<n-2; i++){
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp1->next->next;
    
    free(temp2);
}

void printnode(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}