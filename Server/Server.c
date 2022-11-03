#include"../Server/Server.h"
#include"../Double_Linked_List/Double_Linked_List.h"


EN_Operation_Status Add_Employee(ST_linkedList_t* L)
{ 
    EN_LinkedList_state_t Error;
    ST_Employee_data_t employee;
    printf("Enter Employee Data\n");
    printf("********************************\n");
    if( Employee_Title(&employee)!= PASS)
    {
        Error = Adding_newEmployee_Failed;
        printf("ADDING NEW EMPLOYEE FAIL\a\n");
        return Error;
    }
    if(Employee_Name(&employee)!= PASS)
    {
        Error = Adding_newEmployee_Failed;
        printf("ADDING NEW EMPLOYEE FAIL\a\n");
        return Error;
    }
    if(Employee_Id(&employee,L)!= PASS)
    {
        Error = Adding_newEmployee_Failed;
        printf("ADDING NEW EMPLOYEE FAIL\a\n");
        return Error;
    }
    if(Employee_Age(&employee)!= PASS)
    {
        Error = Adding_newEmployee_Failed;
        printf("ADDING NEW EMPLOYEE FAIL\a\n");
        return Error;
    }
    if(Employee_Salary(&employee)!= PASS)
    {
        Error = Adding_newEmployee_Failed;
        printf("ADDING NEW EMPLOYEE FAIL\a\n");
        return Error;
    }
     if( DLL_Append_Node(L,employee)!= LL_OK)
    {
        Error = Adding_newEmployee_Failed;
        printf("ADDING NEW EMPLOYEE FAIL\a\n");
        return Error;
    }
    
    Error = Successed;
    return Error;
}

EN_Operation_Status Delete_Employee(ST_linkedList_t* L)
{
    EN_LinkedList_state_t Error;
    ST_Employee_data_t employee;
    printf("Enter The Employee ID:  ");
    scanf("%d", &employee.id);
    fflush(stdin);
    if(DLL_Delete__Node_DepandOn_Value(L, employee)!= LL_OK)
    {
        Error = Removing_Employee_Failed;
        return Error;
    }
    Error = Successed;
    return Error;
    
}
EN_Operation_Status Modify_Employee(ST_linkedList_t* L)
{
    EN_LinkedList_state_t Error;
    ST_Employee_data_t employee,NEW_Employee;
    
    printf("Enter The Employee ID:  ");
    scanf("%d", &employee.id);
    fflush(stdin);
    ST_Node_t * P = DLL_Search_Node(L,employee);
    if(P != NULL)
    {
        printf("**********************THIS IS THE EMPLOYEE OLD DATA***************************\n");
        printf("Title:%s \n",P->data.title);
        printf("Name:%s \n",P->data.name);
        printf("ID:%d \n",P->data.id);
        printf("Salary:%0.2f \n",P->data.salary);
        printf("Age:%d \n",P->data.age);
        printf("****************************ENTER THE NEW DATA*********************************\n");
        if( Employee_Title(&NEW_Employee)!= PASS)
        {
            Error = Editing_EmployeeData_Failed;
            printf("EDITING EMPLOYEE FAIL\a");
            return Error;
        }
        if(Employee_Name(&NEW_Employee)!= PASS)
        {
            Error = Editing_EmployeeData_Failed;
            printf("EDITING EMPLOYEE FAIL\a");
            return Error;
        }
        if(Employee_Age(&NEW_Employee)!= PASS)
        {
            Error = Editing_EmployeeData_Failed;
            printf("EDITING EMPLOYEE FAIL\a");
            return Error;
        }
        if(Employee_Salary(&NEW_Employee)!= PASS)
        {
            Error = Editing_EmployeeData_Failed;
            printf("EDITING EMPLOYEE FAIL\a");
            return Error;
        }
        if(DLL_Edit_Node(L,employee,NEW_Employee)!= LL_OK )
        {
            Error = Editing_EmployeeData_Failed;
            return Error;
        }
        
        Error = Successed;
        return Error;
    }


}
EN_Operation_Status Display_All_Employees(ST_linkedList_t* L)
{
    EN_Operation_Status Error;
    (DLL_Diplay(L)!= LL_OK)?(Error = DISPLAY_ALL_FAILED):(Error = Successed);
    if(Error == DISPLAY_ALL_FAILED)
    {
        printf("FAIL TO DISPLAY ALL EMPLOYEES OR LIST MAYBE EMPTY\a\n");
    }
    return Error;
}

EN_Operation_Status Display_Specific_Employee(ST_linkedList_t* L)
{
    EN_LinkedList_state_t Error;
    uint32_t Val_ID;
    printf("Enter The Employee ID:  ");
    scanf("%d", &Val_ID);
    fflush(stdin);
   if( DLL_Print_Specific_Employee(L,Val_ID) == NULL)
   {
        printf("Employee Data Not found\a\n");
        Error = DISPLAY_SPACIFIC_FAILED;
        return Error;
   }
    Error = Successed;
    return Error;
}
