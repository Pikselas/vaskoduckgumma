#include"Stack.h"
#include"Queue.h"
#include<iostream>
int main()
{
    QUEUE stk = create_queue();
    push_queue(&stk,10);
    push_queue(&stk,20);
    push_queue(&stk,30);
    std::cout<<peek_queue(&stk);
    pop_queue(&stk);
    std::cout<<peek_queue(&stk);
    return 0;
}