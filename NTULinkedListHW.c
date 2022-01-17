#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode* next;

}ListNode;

typedef struct LinkedList{
    ListNode* head;
    int size;
}LinkedList;


ListNode* findNode(LinkedList ll, int i);
ListNode* generateNode(int data);
int insertNode(LinkedList *ll, int i, int item);
void printNodes(ListNode* node);

int main(){

    ListNode *head; 
    ListNode *temp;
    
    // Create linked list of size 3
    temp = generateNode(1);
    head = temp;
    temp->next = generateNode(2);
    temp = temp->next;
    temp->next = generateNode(3);
    temp->next->next =NULL;
    
    //wrp in ll struct
    LinkedList ll;
    ll.head = head;
    ll.size = 3;

    //test code for findnode
    ListNode* finding = findNode(ll, 2);
    printf("%d\n", finding->val);
    

    //test code for insertNode
    insertNode(&ll, 3, 4);
    printNodes(ll.head);

}

ListNode *findNode(LinkedList ll, int i){
    ListNode *temp = ll.head;
    if (temp==NULL || i < 0|| i > ll.size)
        return NULL;
    while (i > 0){
    temp = temp->next;
    if (temp == NULL)
        return NULL;
    i--;
    }
        
        return temp;
}

ListNode* generateNode(int data){
    ListNode* temp = (ListNode*) malloc(sizeof(ListNode));
    temp->val = data;
    temp->next = NULL; 
    return temp;
}

int insertNode(LinkedList *ll, int i, int item){
    ListNode *pre, *newNode;
    ListNode **ptrHead = &ll->head;

    if (i == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->val = item;
        newNode->next = ll->head;
        ll->head = newNode;

    return 1;
    }
    else if ((pre = findNode(*ll, i-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->val = item;
        newNode->next = pre->next;
        pre->next = newNode;
        return 1;
    }
    return 0;
}

void printNodes(ListNode* node){
    if (node == NULL) return;
    printf("%d ", node->val);
    printNodes(node->next);
}