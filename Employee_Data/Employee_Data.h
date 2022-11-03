#ifndef EMPLOYEE_DATA_H
#define EMPLOYEE_DATA_H

/****************************************include*******************************************/
#include"../Double_Linked_List/Double_Linked_List.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/******************************************ENUM************************************************/
typedef enum Employee_DataError
{
    PASS,
    NAME_NOK,
    AGE_NOK,
    TITLE_NOK,
    ID_NOK,
    NOT_AUTHOR
}EN_Employee_DataError;

/*****************************************FUNCTIONS*************************************/
EN_Employee_DataError Employee_Name(ST_Employee_data_t* Emp);
EN_Employee_DataError Employee_Age(ST_Employee_data_t* Emp);
EN_Employee_DataError Employee_Id(ST_Employee_data_t* Emp, ST_linkedList_t* L);
EN_Employee_DataError Employee_Title(ST_Employee_data_t* Emp);
EN_Employee_DataError Employee_Salary(ST_Employee_data_t* Emp);





#endif // !EMPLOYEE_DATA_H
