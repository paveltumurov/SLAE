#include <iostream>
#include "../src/TDM.cpp"
int main()
{
    std::vector<double> ma,la,ha,fa,x;
    ma = {1,2,3,4};
    la = {1,0,2};
    ha = {1,1,2};
    fa = {1,0,0,0};
    TDM a(la,ma,ha);
    x = a.solution(fa);
    for (int i = 0;i<x.size();i++)
    {
        std::cout<<x[i]<<std::endl;
    }
}