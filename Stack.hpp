#pragma once
#include<memory>
template<typename StackType>
class ArrayStack
{
    private:
        size_t INTERNAL_COUNTER = -1;
        size_t MAX_SIZE;
        std::unique_ptr<StackType[]> STACK;
    public:
        ArrayStack(size_t MAX_SIZE = 2345) : MAX_SIZE(MAX_SIZE)
        {
            STACK = std::make_unique<StackType[]>(MAX_SIZE);
        }
        ~ArrayStack() = default;
    public:
        void Push(StackType& Data)
        {
            if(INTERNAL_COUNTER != MAX_SIZE - 1)
            {
                STACK[++INTERNAL_COUNTER] = Data;
            }
            else
            {
                //STACK OVERFLOW
            }
        }
        void Pop()
        {
            if(INTERNAL_COUNTER != -1)
            {
                INTERNAL_COUNTER--;
            }
            else
            {
                //UNDERFLOW
            }
        }
        StackType Peek()
        {
            if(INTERNAL_COUNTER != -1)
            {
                return STACK[INTERNAL_COUNTER];
            }
            else
            {
                return StackType();
            }
        }
};