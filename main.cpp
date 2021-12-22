#include"StackList.h"
#include<iostream>
int main()
{
    StackList *  STL;
    push_stackList(&STL , 10);
    push_stackList(&STL , 30);
    push_stackList(&STL , 40);
    std::cout<<peek_StackList(&STL)<<std::endl;
    pop_StackList(&STL);
    std::cout<<peek_StackList(&STL);
    return 0;
}