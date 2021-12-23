#pragma once
typedef int QueueListType;
#include<stdlib.h>
struct QueueListNode
{
    QueueListType data;
    struct QueueListNode* next = nullptr;
};
struct QueueList
{
    struct QueueListNode * FRONT = nullptr ;
    struct QueueListNode * BACK = nullptr ;
};

void push_QueueList(struct QueueList * queue_list , QueueListType Data)
{
     if(queue_list->BACK != nullptr)
     {
        queue_list->BACK->next = (struct QueueListNode *) malloc(sizeof(QueueListNode));
        queue_list->BACK = queue_list->BACK->next;
     }
     else
     {
        queue_list->BACK =  (struct QueueListNode *) malloc(sizeof(QueueListNode));
     }
     queue_list->BACK->data = Data;
     if(queue_list->FRONT == nullptr)
     {
         queue_list->FRONT = queue_list->BACK;
     }
}
void pop_QueueList(struct QueueList* queue_list)
{
    if(queue_list->FRONT != nullptr)
    {
        struct QueueListNode* tmp = queue_list->FRONT;
        queue_list->FRONT = queue_list->FRONT->next;
        free(tmp);
    }
}
QueueListType peek_QueueList(struct QueueList* queue_list)
{
  if(queue_list->FRONT != nullptr)
  {
      return queue_list->FRONT->data;
  }
  else
  {
      return QueueListType();
  }
}