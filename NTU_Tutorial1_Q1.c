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
    student1.InfoPtr = &student1.Info;
    
    //2 ways to get age from studentPtr
    
    int age1 = studentPtr->Info.age;
    int age2 = studentPtr->InfoPtr->age;
    printf("age1: %d, age3: %d\n", age1, age2);

    //2 ways to get age from studentPtrPtr
    int age3 = (*studentPtrPtr)->Info.age;
    int age4 = (*studentPtrPtr)->InfoPtr->age;
    
    printf("age3: %d, age4: %d", age3, age4);
 
}