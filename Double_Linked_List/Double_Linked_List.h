#ifndef DOUBLE_LINKED_LIST_H_
#define DOUBLE_LINKED_LIST_H_

/****************************************include*******************************************/
#include"../Utilities/Std_Types.h"

/*************************************Structure*******************************************/
typedef struct Employee_Data
{
    uint8_t name[50];
    uint8_t title[20];
    float32_t salary;
    uint32_t id;
    uint8_t age;

}ST_Employee_data_t;

typedef struct node_tag
{
    ST_Employee_data_t data;
    struct node_tag* next;
    struct node_tag* prev;
}ST_Node_t;

typedef struct
{
    ST_Node_t* head;
    ST_Node_t* tail;
    uint16_t size;
}ST_linkedList_t;

/******************************************ENUM************************************************/
typedef enum linked_list_state_tag
{
    LL_NODE_NOT_CREATED,
    NODE_NOT_FOUND,
    LL_OK,
    LL_EMPTY,
    LL_NOT_EMPTY,
    LL_APPEND_FLAG,
    INVAILED_POS
}EN_LinkedList_state_t;


/*****************************************FUNCTIONS*************************************/
ST_linkedList_t* DLL_Create_List(void);
EN_LinkedList_state_t DLL_Append_Node(ST_linkedList_t* L, ST_Employee_data_t val);
EN_LinkedList_state_t DLL_Diplay(ST_linkedList_t* L);
ST_Node_t* DLL_Search_Node(ST_linkedList_t* L, ST_Employee_data_t val);
EN_LinkedList_state_t DLL_Free_List(ST_linkedList_t* L);
EN_LinkedList_state_t DLL_Delete__Node_DepandOn_Value(ST_linkedList_t* L, ST_Employee_data_t val);
EN_LinkedList_state_t DLL_Delete_Node_DepandOn_Position(ST_linkedList_t* L, uint16_t pos);
EN_LinkedList_state_t DLL_Insert_Node_Position(ST_linkedList_t* L, ST_Employee_data_t val, uint16_t pos);
EN_LinkedList_state_t DLL_Edit_Node(ST_linkedList_t* L, ST_Employee_data_t oldVal, ST_Employee_data_t newVal);
ST_Node_t* DLL_Print_Specific_Employee(ST_linkedList_t*L,uint32_t val);




#endif // !_DOUBLE_LINKED_LIST_H_

