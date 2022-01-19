#include <stdlib.h>
#include <stdio.h>

struct person {
char firstName [15];
char lastName [15];

struct {
int age ;
float height ;
float weight ;
char firstName [15];
} Info ,*InfoPtr ;

struct person * personP ; //error here, need to be pointer

} student1 ;

typedef struct person person_t ;
person_t * studentPtr = &student1 ;
person_t ** studentPtrPtr = &studentPtr ;

int main(){
    student1.Info.age = 21;
    
    //to get age from studentPtr
    
    int age1 = studentPtr->Info.age;
    printf("age1: %d\n", age1);

    //to get age from studentPtrPtr
    int age2 = (*studentPtrPtr)->Info.age;
    printf("age2: %d", age2);
 
}