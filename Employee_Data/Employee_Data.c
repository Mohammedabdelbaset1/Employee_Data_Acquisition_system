#include"../Employee_Data/Employee_Data.h"
#include"../Utilities/Std_Types.h"
#include<conio.h>
#include<stdlib.h>


uint8_t PSWD[6] = "12345";

EN_Employee_DataError Employee_Name(ST_Employee_data_t* Emp)
{
    EN_Employee_DataError Error;
    uint32_t length = 0;
    printf("Enter Employee Name: ");
    fflush(stdin);
    gets(Emp->name);
    fflush(stdin);
    length = strlen(Emp->name);
    if (Emp->name == NULL)
    {
        Error = NAME_NOK;
        printf("wrong name \n");
        return Error;
    }
    else if ((length < 10) || (length > 29))
    {
        Error = NAME_NOK;
        printf("wrong name length \n");
        return Error;
    }
    else
    {
        int i;
        for (i = 0; i < length; i++)
        {
            if ((((Emp->name[i] >= 'A') && (Emp->name[i] <= 'Z')) || ((Emp->name[i] >= 'a') && (Emp->name[i] <= 'z')) || (Emp->name[i] == 32)))
            {
                Error = PASS;
            }
            else
            {
                Error = NAME_NOK;
                printf("NOK %c  Special Characters not allowed \n", Emp->name[i]);
                break;

            }
        }
    }
    return Error;
}
EN_Employee_DataError Employee_Age(ST_Employee_data_t* Emp)
{
    EN_Employee_DataError Error;
    printf("Enter Age: ");
    scanf("%d", &Emp->age);
    fflush(stdin);
    if (((Emp->age < 18) || (Emp->age > 59)))
    {
        Error = AGE_NOK;
        printf("unvalid Age  \n");
        return Error;
    }
    else
    {
        Error = PASS;
    }
    return Error;
}
EN_Employee_DataError Employee_Id(ST_Employee_data_t* Emp, ST_linkedList_t* L)
{
    EN_Employee_DataError Error;
    printf("Enter NEW ID Within the Interval (1000 - 10000):  ");
    fflush(stdin);
    scanf("%d", &Emp->id);
    fflush(stdin);
    if (DLL_Search_Node(L, *Emp) != NULL)
    {
        printf("this ID has been taken can't be used\n");
        Error = ID_NOK;
        return Error;
        
    }
    if (((Emp->id < 1000) || (Emp->id > 10000)))
    {
        Error = ID_NOK;
        printf("unvalid ID  \n");
        return Error;
    }
    else
    {
        Error = PASS;
    }
    return Error;
}
EN_Employee_DataError Employee_Title(ST_Employee_data_t* Emp)
{
    EN_Employee_DataError Error;
    uint32_t length=0;
    printf("Enter Title: \n**************************************\nTitle Should Follow the following 3 capital letters refer\
to position and 1 digit refer to degree\n1.ENGx\n2.ACCx\n3.MAAx\n4.TECx\n5.CTO\n6.CEO\nwhere x is: [1-5]\n");
    gets(Emp->title);
    fflush(stdin);
   
    length = strlen(Emp->title);
    if ((length != 4))
    {
        Error = TITLE_NOK;
        printf("unvalid Title \n");
        return Error;
    }
    else
    {
        Error = PASS;
    }
    return Error;
}
EN_Employee_DataError Employee_Salary(ST_Employee_data_t* Emp)
{
    EN_Employee_DataError Error;
    uint8_t pa[6];
    int i = 0;
    printf("Enter Salary: \n");
    printf("This Operation need Authority.\nEnter password:");
    do
    {
        pa[i] = _getch();
        if (pa[i] != '\r')
        {
            printf("*");
        }
        i++;

    } while (pa[i - 1] != '\r');
    pa[i - 1] = '\0';
    if (strcmp(pa, PSWD))
    {
        Error = NOT_AUTHOR;
        printf("Not authorized for this operation\n");
        return Error;
    }

    printf("\nEnter Salary: ");
    fflush(stdin);
    scanf("%f", &Emp->salary);
    fflush(stdin);
    Error = PASS;
    return Error;

}
