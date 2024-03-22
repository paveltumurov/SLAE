#include "chebyshev.hpp"
#include "iterations.hpp"
#include <chrono>
int main(){
    std::vector<double> b,val = {30, 2, 3, 2,20,3,3,3,50};
    std::vector<double> r = {0,3,6,9};
    std::vector<double> c = {0,1,2,0,1,2,0,1,2};
    CSRMatrix A(val, c, r , 3, 3);
    std::vector<double> x0 = {0,0,0};
    b = {1,2,3};
    for (double tol=1; tol>0.000001; tol/=1.5){
        auto start = std::chrono::high_resolution_clock::now();
        cheb_mpi(A,b,x0, tol, 19.422739, 50.786481, 3);
        //gauss_zeidel(A,b,x0, tol, 32);
        //jacobi(A,b,x0, tol, 32);
        //mpi(A,b,x0, tol, 0.028486, 32);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout<<tol<<" "<<diff.count()<<std::endl;
    }
    //cheb_mpi(A,b,x0, 0.00000001, 19.422739, 50.786481, 5);
    

}
