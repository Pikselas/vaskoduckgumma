#include"SinglyList.hpp"
int main()
{
   SinglyList<int> LS , LK;
   LS.push_front(10);
   LS.push_front(11);
   LS.push_front(12);
   LS.insert(0,19);
   LS.remove(2);
   
   LK = LS; // copy

   //LK += LS; // concatenate

   ~LK; //reverse
   LK.traverse();
    return 0;
}