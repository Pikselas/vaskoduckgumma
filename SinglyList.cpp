#include"SinglyList.hpp"
template <typename ListType>
SinglyList<ListType>::SinglyList(const SinglyList& List)
{
    *this = List;
}
template <typename ListType>
SinglyList<ListType>& SinglyList<ListType>::operator = (const SinglyList& List)
{
    if(List.HEAD != nullptr)
    {
        HEAD = std::make_shared<NODE>(List.HEAD->DATA);
        auto TmpFromTarget = List.HEAD->NEXT;
        auto Tmp = HEAD;
        while(TmpFromTarget != nullptr)
        {
            Tmp->NEXT = std::make_shared<NODE>(TmpFromTarget->DATA);
            TmpFromTarget = TmpFromTarget->NEXT;
            Tmp = Tmp->NEXT;
        }
    }
    return *this;
}
template <typename ListType>
SinglyList<ListType>& SinglyList<ListType>::operator += (const SinglyList& List)
{
    auto TmpFromTarget = List.HEAD;
    if(HEAD == nullptr)
    {
        HEAD = std::make_shared<NODE>(List.HEAD->DATA);
        TmpFromTarget = TmpFromTarget->NEXT;
    }
    auto Tmp = HEAD;
    while(Tmp->NEXT != nullptr)
    {
        Tmp = Tmp->NEXT;
    }
    while(TmpFromTarget != nullptr)
    {
        Tmp->NEXT = std::make_shared<NODE>(TmpFromTarget->DATA);
        TmpFromTarget = TmpFromTarget->NEXT;
        Tmp = Tmp->NEXT;
    }
    return *this;
}
template <typename ListType>
SinglyList<ListType>& SinglyList<ListType>::operator ~()
{
    if(HEAD != nullptr && HEAD->NEXT != nullptr)
    {
        auto current = HEAD;
        std::shared_ptr<NODE> prev = nullptr;
        while(current->NEXT != nullptr)
        {
            auto tmp = current->NEXT;
            current->NEXT = prev;
            prev = current;
            current = tmp;
        }
        current->NEXT = prev;
        HEAD = current;
    }
    return *this;
}
template <typename ListType>
void SinglyList<ListType>::push_back(ListType Data)
{
    if(HEAD == nullptr)
    {
        HEAD = std::make_shared<NODE>(Data);
    }
    else
    {
        auto Tmp = HEAD;
        while(Tmp->NEXT != nullptr)
        {
            Tmp = Tmp->NEXT;
        }
        Tmp->NEXT = std::make_shared<NODE>(Data);
    }
}
template <typename ListType>
void SinglyList<ListType>::push_front(ListType Data)
{
    if(HEAD == nullptr)
    {
        HEAD = std::make_shared<NODE>(Data);
    }
    else
    {
        HEAD = std::make_shared<NODE>(Data,HEAD);
    }
}
template <typename ListType>
void SinglyList<ListType>::insert(size_t pos,ListType Data)
{
    if(pos != 0)
    {
        auto Tmp = HEAD;
        size_t i = 1;
        while(i < pos)
        {
            Tmp = Tmp->NEXT;
            i++;
        }
        Tmp->NEXT = std::make_shared<NODE>(Data , Tmp->NEXT);
    }
    else
    {
        HEAD = std::make_shared<NODE>(Data , HEAD);
    }
}
template <typename ListType>
void SinglyList<ListType>::remove(size_t pos)
{
    if(pos != 0)
    {
        size_t i = 1;
        auto Tmp = HEAD;
        while( i < pos)
        {
            Tmp = Tmp->NEXT;
            i++;
        }
        Tmp->NEXT = Tmp->NEXT->NEXT;
    }
    else
    {
        HEAD = HEAD->NEXT;
    }
}
template <typename ListType>
void SinglyList<ListType>::traverse() const
{
    auto Tmp = HEAD;
    while(Tmp != nullptr)
    {
        std::cout<<Tmp->DATA << std::endl;
        Tmp = Tmp->NEXT;
    }
}