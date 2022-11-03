#ifndef SERVER_H
#define SERVER_H

/****************************************include*******************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../Double_Linked_List/Double_Linked_List.h"
#include"../Employee_Data/Employee_Data.h"

/******************************************ENUM************************************************/
typedef enum Operation_Status
{
    Successed,
    Adding_newEmployee_Failed,
    Removing_Employee_Failed,
    Editing_EmployeeData_Failed,
    DISPLAY_ALL_FAILED,
    DISPLAY_SPACIFIC_FAILED
}EN_Operation_Status;

/*****************************************FUNCTIONS*************************************/
EN_Operation_Status Add_Employee(ST_linkedList_t* L);
EN_Operation_Status Delete_Employee(ST_linkedList_t* L);
EN_Operation_Status Modify_Employee(ST_linkedList_t* L);
EN_Operation_Status Display_All_Employees(ST_linkedList_t* L);
EN_Operation_Status Display_Specific_Employee(ST_linkedList_t* L);



#endif // !SERVER_H
