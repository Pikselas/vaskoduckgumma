#pragma once
#include<stdlib.h>
typedef int QueueType;
struct QUEUE
{
  long FRONT = -1;
  long BACK  = -1;
  unsigned long MAX_SIZE = 0;
  QueueType* ARRAY = nullptr;
};
struct QUEUE create_queue(unsigned long Size = 1234)
{
    return {-1,-1,Size,(QueueType *)malloc(sizeof(QueueType) * Size)};
}
void push_queue(struct QUEUE* queue,QueueType Data)
{
    if(queue->BACK != (queue->MAX_SIZE - 2))
    {
        queue->ARRAY[++(queue->BACK)] = Data;
        if(queue->FRONT == -1)
        {
            queue->FRONT++;
        }
    }
    else
    {
        //OVERFLOW
    }
}
void pop_queue(struct QUEUE * queue)
{
    if(queue->FRONT != -1)
    {
     queue->FRONT++;
     if(queue->FRONT > queue->BACK )
     {
         queue->FRONT = queue->BACK = -1;
     }
    }
    else
    {
        //UNDERFLOW
    }
}
QueueType peek_queue(struct QUEUE * queue)
{
    if(queue->FRONT != -1)
    {
        return queue->ARRAY[queue->FRONT];
    }
    else
    {
        return QueueType();
    }
}