#include <stdio.h>
#include <stdlib.h>
#include "SDBAPP.h"

/*it has a super loop it will make 
your project until the user chose to exit you 
will ask the user to choose between these 
options*/
void SDB_APP (){
    int choise = 0;
    while(1){
        printf("****************************************************\n");
        printf("0 --> exit\n");
        printf("1 --> add entry\n");
        printf("2 --> get used size in database\n");
        printf("3 --> read student data\n");
        printf("4 --> get the list of all student IDs\n");
        printf("5 --> check is ID is existed\n");
        printf("6 --> delete student data\n");
        printf("7 --> check is database is full\n");
        printf("****************************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choise);
        SDB_action(choise);
    }
}
/* it well takes the user choice 
and call the responding function for this 
choice.*/
void SDB_action (uint8 choice){
    uint32 id = 0;
    switch (choice) {
        case 0:
            exit(0);
            break;
        case 1:
            SDB_AddEntry ();
            break;
        case 2:
            printf("The used size is %d\n", SDB_GetUsedSize());
            break;
        case 3:
            printf("Enter ID: ");
            scanf("%d", &id);
            SDB_ReadEntry (id);
            break;
        case 4:
            SDB_GetList ();
            break;
        case 5:
            printf("Enter ID: ");
            scanf("%d", &id);
            if (SDB_IsIdExist (id)){
                printf("Student's ID %d exists\n", id);
            }
            else {
                printf("Student's ID %d does not exist\n", id);
            }
            break;
        case 6:
            printf("Enter ID: ");
            scanf("%d", &id);
            SDB_DeletEntry (id);
            break;
        case 7:
            if (SDB_IsFull()){
                printf("Database is full\n");
            }
            else {
                printf("Database is not full\n");
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}