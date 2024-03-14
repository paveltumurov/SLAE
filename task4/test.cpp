#include "iterations.hpp"
#include <chrono>
int main(){
    std::vector<double> b,val = {30,2,3,2,20,3,3,3,50};
    std::vector<double> r = {0, 3,6,9};
    std::vector<double> c = {0,1,2,0,1,2,0,1,2};
    CSRMatrix A(val, c, r , 3, 3);
    //A.show();
    b = {1,2,3};
    gauss_zeidel(A, b, b, 0.000001, 100);
    // for(double i=1;i<10000001;i*=10){
    //     double tol = 1/i;
    //     auto start = std::chrono::high_resolution_clock::now();
    //     mpi(A,b,b, tol,0.0285, 100);
    //     auto end = std::chrono::high_resolution_clock::now();
    //     std::chrono::duration<double> diff = end-start;
    //     std::cout<<tol<<" "<<diff.count()<<std::endl;
    // }
    

}
