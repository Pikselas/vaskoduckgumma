//compile with cl .\Matrix.cpp -std:c++latest /EHsc

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
template<typename OpType>
v2Dtype MatrixOperation(const v2Dtype& v1,const v2Dtype& v2)
{
    v2Dtype v;
    if(!v1.empty() && !v2.empty())
    {
        if(v1.size() == v2.size() && v1.front().size() == v2.front().size())
        {
            std::ranges::transform(v1,v2,std::back_inserter(v),[](const auto& I1,const auto& I2){
                 vType vCol;
                 std::ranges::transform(I1,I2,std::back_inserter(vCol),OpType());
                 return vCol;
            });
        }
    }
    return v;
}
void Transpose(v2Dtype& v)
{
    auto Row = v.size();
    auto Col = v.front().size();
    auto i = Row;
    auto j = Col;
    for(i = 0 ; i < Row ; i++)
    {
        for( j = 0;j < Col ;j++ )
        {
            auto Tmp = v[i][j];
            v[i][j] = v[j][i];
            v[j][i] = Tmp;
        }
        Traverse(v);
        std::cout<<std::endl;
    }
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
    int r , c;
    std::cout<<"\nENTER ELEMENT ROW AND COLUMN FOR 1ST MATRIX:";
    std::cin >> r >> c;
    v2Dtype v1(r , vType(c ,0));
    std::cout<<"\nENTER ELEMENTS";
    for(auto& elm : v1)
    {
        for(auto& e : elm)
        {
            std::cin>>e;
        }
    }
    std::cout<<"\nENTER ELEMENT ROW AND COLUMN FOR 1ST MATRIX:";
    std::cin >> r >> c;
    v2Dtype v2(r , vType(c ,0));
    std::cout<<"\nENTER ELEMENTS";
    for(auto& elm : v2)
    {
        for(auto& e : elm)
        {
            std::cin>>e;
        }
    }
    while(true)
    {
    std::cout<<"ENTER CHOICE\n1.ADD\n2.SUBTRACT\n3.MULTIPLY\n4.TRAVERSE";
    std::cin>>r;
    switch (r)
    {
    case 1:
      Traverse(MatrixOperation<std::plus<int>>(v1,v2));
     break;
    case 2:
      Traverse(MatrixOperation<std::minus<int>>(v1,v2));
    break;
    case 3:
      Traverse(Multiply(v1,v2));
     break;
    case 4:
      Traverse(v1);
      std::cout<<std::endl;
      Traverse(v2);
     break;
    }
    }
return 0;
}