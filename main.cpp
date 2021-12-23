#include"QueueList.h"
#include<iostream>
int main()
{
    QueueList QL;
    push_QueueList(&QL , 10);
    push_QueueList(&QL,20);
    std::cout<<peek_QueueList(&QL) << std::endl;
    pop_QueueList(&QL);
    std::cout<<peek_QueueList(&QL);
    return 0;
}