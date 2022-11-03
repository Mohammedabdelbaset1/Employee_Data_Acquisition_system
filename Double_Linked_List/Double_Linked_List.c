#include"../Double_Linked_List/Double_Linked_List.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>




ST_linkedList_t* DLL_Create_List(void)
{

    ST_linkedList_t* list = (ST_linkedList_t*)calloc(1, sizeof(ST_linkedList_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

EN_LinkedList_state_t DLL_Append_Node(ST_linkedList_t* L, ST_Employee_data_t val)
{
    ST_Node_t* new_node = (ST_Node_t*)calloc(1, sizeof(ST_Node_t));
    if (new_node == NULL)
    {
        return LL_NODE_NOT_CREATED;
    }
   strcpy_s(new_node->data.name,sizeof(new_node->data.name), val.name);
    new_node->data.age = val.age;
    new_node->data.salary = val.salary;
    new_node->data.id = val.id;
    strcpy_s(new_node->data.title,sizeof(new_node->data.title), val.title);
    new_node->next = NULL;
    new_node->prev = NULL;

    if (L->head == NULL && L->tail == NULL)
    {
        L->head = new_node;
        L->tail = new_node;
    }
    else
    {
        L->tail->next = new_node;
        new_node->prev = L->tail;
        L->tail = new_node;
    }
    L->size++;
    return LL_OK;
}

EN_LinkedList_state_t DLL_Diplay(ST_linkedList_t* L)
{

    if (L->head == NULL && L->tail == NULL)
    {
        //printf("list is empty \n");
        return LL_EMPTY;

    }
    ST_Node_t* current = L->head;
    while (current != NULL)
    {
        printf("****************************************\n");
        printf("Title: %s\n", current->data.title);
        printf("Name: %s\n", current->data.name);
        printf("ID: %d\n", current->data.id);
        printf("Salary: %0.2f\n", current->data.salary);
        printf("Age: %d\n", current->data.age);
        current = current->next;
    }
    printf("\n");
    return LL_OK;
}

ST_Node_t* DLL_Search_Node(ST_linkedList_t* L, ST_Employee_data_t val)
{
    if (L->head == NULL && L->tail == NULL)
    {
        //printf("list is empty \n");
        return NULL;
    }
    ST_Node_t* current = L->head;

    while (current != NULL)
    {
        if (current->data.id == val.id)
        {
            return current;
        }
        current = current->next;
    }
    return current;
}

EN_LinkedList_state_t DLL_Free_List(ST_linkedList_t* L)
{
    if (L->head == NULL && L->tail == NULL)
    {
        printf("list is empty \n");
        return LL_EMPTY;
    }
    ST_Node_t* current = L->head;
    while (current != NULL)
    {
        L->head = L->head->next;
        free(current);
        current = L->head;
    }
    L->tail = NULL;
    L->size = 0;
    return LL_EMPTY;
}

EN_LinkedList_state_t DLL_Delete__Node_DepandOn_Value(ST_linkedList_t* L, ST_Employee_data_t val)
{
    if (L->head == NULL && L->tail == NULL)
    {
        printf("list is empty \n");
        return LL_EMPTY;
    }

    ST_Node_t* current = L->head;
    if (L->head->data.id == val.id)
    {
        L->head = L->head->next;
        if (L->head == NULL)
        {
            L->tail = NULL;
        }
        free(current);
        L->size--;
        return LL_OK;
    }
    while (current != NULL && current->data.id != val.id)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("value not found \n");
        return NODE_NOT_FOUND;
    }
    else if (current == L->tail)
    {

        L->tail = L->tail->prev;
        L->tail->next = NULL;
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    free(current);
    L->size--;
    return LL_OK;

}
EN_LinkedList_state_t DLL_Delete_Node_DepandOn_Position(ST_linkedList_t* L, uint16_t pos)
{
    if (L->head == NULL && L->tail == NULL)
    {
        printf("list is empty \n");
        return LL_EMPTY;
    }
    if (pos >= L->size)
    {
        printf("invaild position\n");
        return INVAILED_POS;
    }

    ST_Node_t* current = L->head;
    if (pos == 0)
    {
        L->head = L->head->next;
        if (L->head == NULL)
        {
            L->tail = NULL;
        }
        free(current);
        L->size--;
        return LL_OK;
    }


    for (int i = 0; i < pos; i++)
    {
        current = current->next;
    }
    if (current == L->tail)
    {
        L->tail = L->tail->prev;
        L->tail->next = NULL;

    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

    }
    free(current);
    L->size--;

    return LL_OK;
}

EN_LinkedList_state_t DLL_Insert_Node_Position(ST_linkedList_t* L, ST_Employee_data_t val, uint16_t pos)
{
    if (pos >= L->size)
    {
        DLL_Append_Node(L, val);
        return LL_APPEND_FLAG;
    }
    ST_Node_t* new_node = calloc(1, sizeof(ST_Node_t));
    if (new_node == NULL)
    {
        return LL_NODE_NOT_CREATED;
    }
    new_node->data = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    ST_Node_t* current = L->head;
    if (pos == 0)
    {

        if ((L->head == NULL && L->tail == NULL))
        {
            L->head = new_node;
            L->tail = new_node;
        }
        else
        {
            new_node->next = L->head;
            L->head = new_node;


        }
        L->size++;
        return LL_OK;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;
    }
    new_node->next = current->next;
    current->prev = current;
    current->next = new_node;
    L->size++;

}
EN_LinkedList_state_t DLL_Edit_Node(ST_linkedList_t* L, ST_Employee_data_t oldVal, ST_Employee_data_t newVal)
{
    if (L->head == NULL && L->tail == NULL)
    {
        printf("list is empty \n");
        return LL_EMPTY;
    }
    ST_Node_t* ptr_node = DLL_Search_Node(L, oldVal);

    if (ptr_node == NULL)
    {
        printf("node not found \n");
        return NODE_NOT_FOUND;
    }
    else
    {
        strcpy_s(ptr_node->data.name,sizeof(ptr_node->data.name), newVal.name);
        strcpy_s(ptr_node->data.title, sizeof(ptr_node->data.title), newVal.title);
        ptr_node->data.age = newVal.age;
        ptr_node->data.id = oldVal.id;
        ptr_node->data.salary = newVal.salary;
    }
    return LL_OK;
}
ST_Node_t* DLL_Print_Specific_Employee(ST_linkedList_t*L,uint32_t val)
{
    if (L->head==NULL &&L->tail== NULL)
    {
        //printf("list is empty \n");
        return NULL;
    }
    ST_Node_t* current =L->head;

    while (current!=NULL)
    {
        if (current->data.id==val)
        {
        printf("****************************************\n");
        printf("Title:%s \n",current->data.title);
        printf("Name:%s \n",current->data.name);
        printf("ID:%d \n",current->data.id);
        printf("Salary:%0.2f \n",current->data.salary);
        printf("Age:%d \n",current->data.age);
        break;
        }
        current=current->next;
    }
    
    return current; 
}