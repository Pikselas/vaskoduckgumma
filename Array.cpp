#include<vector>
#include<ranges>
#include<algorithm>
#include<iterator>
#include<iostream>
template<typename dType>
std::vector<dType> Merge(const std::vector<dType>& v1 ,const std::vector<dType>& v2)
{
    std::vector<dType> TempV;
    std::ranges::merge(v1,v2,std::back_inserter(TempV));
    return TempV;
}
template<typename dType>
void Insert(std::vector<dType>& v, int Index , dType data)
{
  auto itr = std::inserter(v,v.begin() + Index);
  *itr = data;
}
template<typename dType>
void Delete(std::vector<dType>& v , int Index)
{
    v.erase(v.begin() + Index);
}
int main()
{
    int ch;
    std::cout<<"ENTER ARRAY SIZE:";
    std::cin>>ch;
    std::vector<int> v(ch,0);
    std::cout<<"\nENTER ELEMNTS:";
    for(auto& elm : v)
    {
        std::cin >> elm;
    }
    while(true)
    {
    std::cout<<"ENTER CHOICE:\n1.TRAVERSE\n2.MERGE\n3.DELETE\n4.INSERT\n5.REVERSE\n6.SEARCH\n7.SORT";
    std::cin>>ch;
    switch(ch)
    {
        case 1:
          for(auto& elm : v)
          {
              std::cout<<elm<<" ";
          }
        break;
        case 2:
         std::cout<<"ELEMENTS FOR MERGING WITH SIZE (first one) : ";
         std::cin>>ch;
         {
             std::vector<int> v2(ch,0);
             for(int& el : v2)
             {
                 std::cin>>el;
             }
             v = Merge(v,v2);
         }
        break;
        case 3:
          std::cout<<"ENTER POSITION:";
          std::cin>>ch;
          Delete(v,ch); 
        break;
        case 4:
            std::cout<<"ENTER POS AND DATA";
            {
                int dt;
                std::cin>>ch>>dt;
                Insert(v,ch,dt);
            }  
        break;
        case 5:
          std::reverse(v.begin(),v.end());
        break;
        case 6:
          std::cout<<"ENTER ELEMENT TO BE SEARCH";
          std::cin>>ch;
          std::cout<<std::distance(std::find(v.begin(),v.end(),ch) , v.begin());
        break;
        case 7:
          std::sort(v.begin(),v.end());
         break;
    }
    }
    return 0;
}