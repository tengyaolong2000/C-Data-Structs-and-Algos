//array based implementation of stack

#include <stdio.h>
#define MAX_SIZE 101

void push(int x);
void pop();
void print_stack();

int A[MAX_SIZE];
int top = -1;

int main(){

}

void push(int x){
    if (top==MAX_SIZE-1){
        printf("Error: Stack Overflow\n");
        return;
    }
    A[++top]=x;
}

void pop(){
    if (top == -1) return;

    --top;
}

void print_stack(){
    printf("Stack: \n");
    for (int i=0; i<= top; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
