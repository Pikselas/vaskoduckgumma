#include<memory>
#include<iostream>
#include<functional>
template <typename ListType>
class SinglyList
{
    private:
     struct NODE
     {
         NODE(ListType Data) : DATA(Data){};
         NODE(ListType Data , std::shared_ptr<NODE> NXT) : DATA(Data) , NEXT(NXT){};
         ListType DATA;
         std::shared_ptr<NODE> NEXT = nullptr;
     };
     std::shared_ptr<NODE>HEAD = nullptr;
    public:
     SinglyList() = default;
     SinglyList(const SinglyList& list);
     SinglyList& operator = (const SinglyList& List);
     SinglyList& operator += (const SinglyList& List);
     SinglyList& operator ~();
    public:
     void push_back(ListType Data);
     void push_front(ListType Data);
     void insert(size_t pos,ListType Data);
     void remove(size_t pos);
     void traverse() const;
};