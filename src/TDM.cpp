#include "TDM.hpp"
#include <iostream>
std::vector<double> TDM::solution(std::vector<double> f)
{
    std::vector <double> p;
    std::vector <double> q;
    
    p.push_back(-this->high_diag[0]/this->main_diag[0]);
    q.push_back( f[0]/this->main_diag[0]);//Найдены первые p и q
    for (int i = 1; i<this->main_diag.size();i++){
        p.push_back(-this->high_diag[i]/(this->low_diag[i-1]*p[i-1]+this->main_diag[i]));
        q.push_back((f[i]-this->low_diag[i-1]*q[i-1])/(this->low_diag[i-1]*p[i-1]+this->main_diag[i]));
    }
    // Найдены все p и q
    int n = this->main_diag.size()-1;
    std::vector <double> x(n+1);
    x[n] = (f[n]-this->low_diag[n-1]*q[n])/(low_diag[n-1]*p[n]+this->main_diag[n]);
    for (int i = n-1; i>=0; i--)
    {
        x[i] = p[i+1]*x[i+1]+q[i];
    }
    return x;
}
// int main()
// {
//     std::vector<double> ma,la,ha,fa,x;
//     ma = {1,2,3,4};
//     la = {1,0,2};
//     ha = {1,1,2};
//     fa = {1,0,0,0};
//     TDM a(la,ma,ha);
//     x = a.solution(fa);
//     for (int i = 0;i<x.size();i++)
//     {
//         std::cout<<x[i]<<std::endl;
//     }
// }

