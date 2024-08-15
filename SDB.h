#ifndef _SDB_H_
#define _SDB_H_

#include "STD.h"

// struct contains all the student info
typedef struct SimpleDb 
{ 
    uint32 Student_ID; 
    uint32 Student_year; 
    uint32 Course1_ID; 
    uint32 Course1_grade; 
    uint32 Course2_ID; 
    uint32 Course2_grade; 
    uint32 Course3_ID; 
    uint32 Course3_grade; 
} student;

// function prototypes
Bool SDB_IsFull ();                                // check if the database is full or not.
uint8 SDB_GetUsedSize ();                          // get how many students in your database have added.
void SDB_AddEntry ();                              // add a new student to the Db.
void SDB_DeletEntry (uint32 id);                   // delete a student from the Db with the given id.
void SDB_ReadEntry (uint32 id);                    // print the data of the selected student given its id
void SDB_GetList ();                               // it gets the number of ids in the count and the list of all ids in list array that’s you get his base address. 
Bool SDB_IsIdExist (uint32 id);                    // Checks if the given id the is Exist

#endif