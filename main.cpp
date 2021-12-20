#include"Stack.h"
#include<iostream>
int main()
{
    STACK stk;
    create_stack(&stk);
    push_stack(&stk,10);
    push_stack(&stk , 30);
    std::cout<<peek_stack(&stk);
    return 0;
}