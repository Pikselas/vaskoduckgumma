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
    std::vector<int> v = {1,2,3,4};
    Delete(v , 0);
    for(auto elm : v)
    {
        std::cout<<elm;
    }
}