
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
 int item ;
 struct node* next ;
} ListNode ;

void Q3F1 ( ListNode * Aptr , ListNode * Bptr );
void Q3F2 ( ListNode *s , ListNode *q );
void buildlist();
void printlist(ListNode *ptrHead);

ListNode* head = NULL;

int main(){
    buildlist();
    ListNode* tail = head;

    while(tail->next!=NULL){tail = tail->next;}
    printlist(head);
    //make it circular
    tail->next = head;
    ListNode* temp1 = head, *temp2 = tail;


    printlist(head);
    Q3F1(temp1->next->next, temp2);
    printlist(head);

    //I GUESS IT KIND OF REMOVES THE NODES BETWEEN Aptr inclusive and Bptr exclusive??? IDK WTFK




    

}

void Q3F1 ( ListNode * Aptr , ListNode * Bptr ){
Q3F2 ( Aptr , Bptr );
Q3F2 ( Bptr , Aptr );
 }
 
void Q3F2 ( ListNode *s , ListNode *q){
ListNode* temp = s;

 while (temp -> next != q) temp = temp -> next ;
 temp -> next = s;
 }


void buildlist(){
    int length, data;
    ListNode* temp1 = (ListNode*) malloc(sizeof(ListNode));
    ListNode* temp2 = NULL;

    printf("Enter the length of your linked list: \n");
    scanf("%d", &length);

    printf("Enter the data of the ListNode at index 0:\n");
    scanf("%d", &data);
    temp1->item=data;
    head = temp1;
    temp2 = temp1;

    for (int i=0; i<length-1;i++){
        temp1  =(ListNode*) malloc(sizeof(ListNode));
        printf("Enter the data of the ListNode at index %d:\n", i+1);
        scanf("%d", &data);
        temp1->item = data;
        temp2->next =  temp1;
        temp2 = temp2->next;
    }
    temp2->next = NULL;
}


//short recursive printlist function to check list
void printlist(ListNode *ptrHead){
    if (ptrHead == NULL) return;
    printf("%d ", ptrHead->item);
    printlist(ptrHead->next);
}