#include "v_ops.hpp"
double operator* (const std::vector<double>& a, const std::vector<double>& b){
    double x=0;
    for (int i =0; i<a.size(); i++){
        x+= a[i]*b[i];
    }
    return x;
};
std::vector<double> operator* (double a, const std::vector<double>& b){
    std::vector <double> x(b.size());
    for(int i = 0; i<b.size(); i++){
        x[i] = a*b[i];
    }
    return x;
};
std::vector<double> operator+ (const std::vector<double>& a, const std::vector<double>& b)
{
    std::vector<double> x(a.size());
    for (int i =0; i<a.size(); i++){
        x[i]= a[i]+b[i];
    }
    return x;
};
std::vector<double> operator- (const std::vector<double>& a, const std::vector<double>& b)
{
    std::vector<double> x(a.size());
    for (int i =0; i<a.size(); i++){
        x[i]= a[i]-b[i];
    }
    return x;
};
void show(const std::vector<double>& v){
    for (int i =0; i< v.size();i++)
    {
        std::cout<<v[i]<<std::endl;
    }
}