//linking linked list nodes

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* link;
} Node;

int main(){
    //Head pointer
    Node* A = NULL;
    
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->data=2;
    temp->link=NULL;
    A = temp;

    //second node
    temp = (Node*) malloc(sizeof(Node));
    temp->data = 4;
    temp->link=NULL;

    //Generic Node traversal
    Node* temp1 = A;
    while(temp1->link != NULL){
        temp1= temp1->link;
    }
    temp1->link=temp;

    //print nodes
    Node* printer = A;
    while(printer != NULL){
        
        printf("%d ", printer->data);
        printer = printer->link;
        
    }
    //OR 
    /*  printf("%d ", printer->data);
        if (printer->link == NULL)
            break;
        printer = printer->link; */


}