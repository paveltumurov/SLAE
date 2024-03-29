#include "grdesc_symgz.hpp"
#pragma #once
int main(){
    std::vector<double> b,val = {30, 2, 3, 2,20,3,3,3,50};
    std::vector<double> r = {0,3,6,9};
    std::vector<double> c = {0,1,2,0,1,2,0,1,2};
    CSRMatrix A(val, c, r , 3, 3);
    std::vector<double> x0 = {0,0,0};
    b = {1,2,3};
    show(symmetric_gz(A,b,x0,0.000001, 1000));
    

}
