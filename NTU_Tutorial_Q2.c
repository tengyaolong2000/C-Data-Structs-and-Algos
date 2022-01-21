//recursive insertNode
//plus some other functions to test correctness of code 


#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
}ListNode;

//function prototypes
void buildlist(ListNode** ptrHead);
void printlist(ListNode *ptrHead);
ListNode* insertNode(ListNode **ptrHead, int i, int item);



//head pointer



int main(){

    ListNode* head =NULL;
    ListNode** ptrHead;
    *ptrHead = head;
    
    buildlist(ptrHead);
    printlist(head);

    //add 9 to index 2, remember index starts from 0
    head = insertNode(ptrHead, 2, 9);
    printf("\n");
    printlist(*ptrHead);
    
    
    
}

//build the linked list
void buildlist(ListNode** ptrHead){
    int length, data;
    ListNode* temp1 = (ListNode*) malloc(sizeof(ListNode));
    ListNode* temp2 = NULL;

    printf("Enter the length of your linked list: \n");
    scanf("%d", &length);

    printf("Enter the data of the ListNode at index 0:\n");
    scanf("%d", &data);
    temp1->data=data;
    *ptrHead = temp1;
    temp2 = temp1;

    for (int i=0; i<length-1;i++){
        temp1  =(ListNode*) malloc(sizeof(ListNode));
        printf("Enter the data of the ListNode at index %d:\n", i+1);
        scanf("%d", &data);
        temp1->data = data;
        temp2->next =  temp1;
        temp2 = temp2->next;
    }
    temp2->next = NULL;
}

//short recursive printlist function to check if list is correct after insertion
void printlist(ListNode *ptrHead){
    if (ptrHead == NULL) return;
    printf("%d ", ptrHead->data);
    printlist(ptrHead->next);
}

//insertnode code
ListNode* insertNode(ListNode **ptrHead, int i, int item){
    
    
     ListNode *newNode = (ListNode*) malloc(sizeof(ListNode));
     newNode->data = item;
     newNode->next = NULL;

    //base case
     if (*ptrHead == NULL || i==0){
         newNode->next = *ptrHead;
         *ptrHead = newNode;
         
     }
     //recursive part
     else{
         //what the fuck it works
         (*ptrHead)->next = insertNode(&((*ptrHead)->next), i-1, item);
     }

    return *ptrHead;

}

     
 