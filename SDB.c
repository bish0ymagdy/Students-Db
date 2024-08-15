#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#include "STD.h"

student studentDb[10];
uint8 pointer = 0;

/*check if the database is full or not*/
Bool SDB_IsFull (){
    if (pointer >= 10) {
        return True;
    }
    else {
        return False;
    }
}

/*get how many students in your database have added*/
uint8 SDB_GetUsedSize (){
    return pointer;
}

/*add a new student to the Db*/
void SDB_AddEntry (){
    if (SDB_IsFull()){
        printf("Database is full\n");
    }
    else {
        printf("Enter ID: ");
        scanf("%d", &studentDb[pointer].Student_ID);
        printf("Enter the year: ");
        scanf("%d", &studentDb[pointer].Student_year);
        printf("Enter Course1's ID: ");
        scanf("%d", &studentDb[pointer].Course1_ID);
        printf("Enter Course1's grade: ");
        scanf("%d", &studentDb[pointer].Course1_grade);
        printf("Enter Course2's ID: ");
        scanf("%d", &studentDb[pointer].Course2_ID);
        printf("Enter Course2's grade: ");
        scanf("%d", &studentDb[pointer].Course2_grade);
        printf("Enter Course3's ID: ");
        scanf("%d", &studentDb[pointer].Course3_ID);
        printf("Enter Course3's grade: ");
        scanf("%d", &studentDb[pointer].Course3_grade);
        pointer++;
    }
}

/*delete a student from the Db with the given id*/
void SDB_DeletEntry (uint32 id){
    for (uint8 i = 0; i < pointer; i++) {
        if (studentDb[i].Student_ID == id) {
            for (uint8 j = i; j < pointer - 1; j++){
                studentDb[j] = studentDb[j + 1];
            }
            pointer--;
            printf("Student with ID %d has been deleted\n", id);
            break;
        }
    }
}

/*print the data of the selected student given its id*/
void SDB_ReadEntry (uint32 id){
    for (uint8 i = 0; i < pointer; i++) {
        if (studentDb[i].Student_ID == id) {
            printf("Student ID: %d\n", studentDb[i].Student_ID);
            printf("Student year: %d\n", studentDb[i].Student_year);
            printf("Course1's ID: %d \t Course1's grade: %d\n", studentDb[i].Course1_ID, studentDb[i].Course1_grade);
            printf("Course2's ID: %d \t Course2's grade: %d\n", studentDb[i].Course2_ID, studentDb[i].Course2_grade);
            printf("Course3's ID: %d \t Course3's grade: %d\n", studentDb[i].Course3_ID, studentDb[i].Course3_grade);
            return;
        }
    }
    printf("Student does not exist");
}

/*it gets the number of ids in the count and 
the list of all ids in list array 
that’s you get his base address*/
void SDB_GetList (){
    student *list = studentDb;
    printf("IDs: ");
    for (uint8 i = 0; i < pointer; i++){
        printf("%d", (*(list + i)).Student_ID);
        if (i < pointer - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

/*Checks if the given id the is Exist*/
Bool SDB_IsIdExist (uint32 id){
    for (uint8 i = 0; i < pointer; i++) {
        if (studentDb[i].Student_ID == id) {
            return True;
        }
        else {
            continue;
        }
    }
    return False;
}