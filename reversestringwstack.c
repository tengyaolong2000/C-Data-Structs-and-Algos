//reverse a string array based stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 20

typedef struct Node{
    int value;
    struct Node* next;
} Node;

void pop();
void push(char x);

char A[MAX_SIZE];
int top = -1;

int main(){
    char word[20];
    printf("Enter the word you want to reverse:\n");
    scanf("%s", word);

    for (int i=0; i<strlen(word);i++){
        push(word[i]);
    }

    for (int i=0; i<strlen(word); i++){
        word[i] = A[top];
        pop();
    }

    printf("%s", word);

}

void push(char x){
    if (top == MAX_SIZE-1) {printf("Max size reached, stackoverflow imminent."); return;}
    A[++top] = x;
}

void pop(){
    if (top == -1) return;
    --top;
}

