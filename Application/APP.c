#include"APP.h"
void init_APP(void)
{

    uint8_t Exit_flag=0;
    ST_linkedList_t* My_List = DLL_Create_List();
    while(1)
    {
        uint8_t Selector;
        printf("********************************EMPLOYEE DATA SYSTEM********************************************\n");
        printf("1.Add A New Empolyee Data:\n");
        printf("2.Modify An Empolyee Data:\n");
        printf("3.Delete An Empolyee Data:\n");
        printf("4.Display A Data Of Empolyee:\n");
        printf("5.Display All Employees Data :\n");
        printf("6.exit\n");
        scanf("%c",&Selector);
        fflush(stdin);
        switch (Selector)
        {
        case '1':
            system("cls");
            Add_Employee(My_List);
            break;
        case '2':
            system("cls");
            Modify_Employee(My_List);
            break;
        case '3':
            system("cls");
            Delete_Employee(My_List);
            break;
        case '4':
            system("cls");
            Display_Specific_Employee(My_List);
            break;
        case '5':
            system("cls");
            Display_All_Employees(My_List);
            break;
        case '6':
            Exit_flag = 1;
            break;
        default:
            printf("Wrong selection\n");
            break;
        }
        if(Exit_flag == 1)
        {
            break;
        }
    }


}