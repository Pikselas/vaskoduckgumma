#include<vector>
#include<iterator>
#include<iostream>
#include<ranges>
#include<algorithm>
using vType = std::vector<int>;
using v2Dtype = std::vector<vType>;

void Traverse(const v2Dtype& v)
{
    for(auto& vCol : v)
    {
        for(auto& colElm : vCol)
        {
            std::cout<<colElm << " ";
        }
        std::cout<<std::endl;
    }
}
v2Dtype Addition(const v2Dtype& v1,const v2Dtype& v2)
{
    v2Dtype v;
    if(!v1.empty() && !v2.empty())
    {
        if(v1.size() == v2.size() && v1.front().size() == v2.front().size())
        {
            std::ranges::transform(v1,v2,std::back_inserter(v),[](const auto& I1,const auto& I2){
                 vType vCol;
                 std::ranges::transform(I1,I2,std::back_inserter(vCol),std::plus<vType::value_type>());
                 return vCol;
            });
        }
    }
    return v;
}
v2Dtype Multiply(const v2Dtype& v1,const v2Dtype& v2)
{
    v2Dtype v;
    const int FirstRowCount = v1.size();
    const int FirstColCount = v1.front().size();
    const int SecondRowCount = v2.size();
    const int SecondColCount = v2.front().size();

    if(FirstColCount == SecondRowCount && FirstRowCount == SecondColCount)
    {
        for(auto Row : v1)
        {
            vType TempRow;
            TempRow.reserve(SecondColCount);
            for(int i = 0; i < SecondColCount ; i++)
            {
                int iTemp = 0;
                for(int j = 0; j < FirstColCount ; j++)
                {
                    iTemp += Row[j] * v2[j][i];
                }
                TempRow.emplace_back(iTemp);
            }
            v.emplace_back(TempRow);
        }
    }

    return v;
}
int main()
{
    v2Dtype v1 = {{1,2},
                  {2,3}},
            v2 = v1;
    Traverse(Multiply(v1,v2));
}