#include"SinglyList.hpp"
int main()
{
    SinglyList<int> ls;
    ls.push_back(10);
    ls.push_front(12);
    ls.push_back(13);
    ls.traverse("\n");
    return 0;
}