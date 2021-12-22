#pragma once
#include<stdlib.h>
typedef int STACK_TYPE;
struct STACK
{
    long INTERNAL_COUNTER = -1;
    unsigned long MAX_SIZE = 0;
    STACK_TYPE * ARRAY = nullptr; 
};
struct STACK create_stack(unsigned long MAX_SIZE = 2345)
{
    return {-1 , MAX_SIZE , (STACK_TYPE*)malloc(sizeof(STACK_TYPE) * MAX_SIZE)};
}
void push_stack(struct STACK* stack,STACK_TYPE Data)
{
    if(stack->MAX_SIZE - 2 != stack->INTERNAL_COUNTER)
    {
        stack->ARRAY[++(stack->INTERNAL_COUNTER)] = Data;
    }
    else
    {
        //OVERFLOW
    }
}
void pop_stack(struct STACK* stack)
{
    if(stack->INTERNAL_COUNTER != -1)
    {
        (stack->INTERNAL_COUNTER)--;
    }
    else
    {
        //UNDERFLOW
    }
}
STACK_TYPE peek_stack(struct STACK* stack)
{
    if(stack->INTERNAL_COUNTER != -1)
    {
        return stack->ARRAY[stack->INTERNAL_COUNTER];
    }
    else
    {
        return STACK_TYPE();
    }
}