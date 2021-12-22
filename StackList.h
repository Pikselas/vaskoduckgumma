#pragma once
#include<stdlib.h>
typedef int StackListType;
struct StackList
{
    StackListType data;
    struct StackList* next = nullptr;
};
void push_stackList(struct StackList ** stack_list , StackListType Data)
{
    struct StackList* temp = (struct StackList *)malloc(sizeof(struct StackList));
    temp->data = Data;
    temp->next = *stack_list;
    *stack_list = temp;
}
void pop_StackList(struct StackList ** stack_list)
{
    if((*stack_list) != nullptr)
    {
        struct StackList * temp = (*stack_list)->next;
        free(*stack_list);
        *stack_list = temp;
    }
}
StackListType peek_StackList(struct StackList ** stack_list)
{
    if(*stack_list != nullptr)
    {
        return (*stack_list)->data;
    }
    else
    {
        return StackListType();
    }
}