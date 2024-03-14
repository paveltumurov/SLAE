#include <vector>
#include "Matrixes.hpp"
#include "v_ops.hpp"
#include <cmath>
#include <iostream>

// std::vector<double> jacobi (const Dense_matrix& A, const std::vector<double>& b, const std::vector<double>& x0,  double tol, int N){
//     int n = b.size();
//     std::vector<double> x = x0;
//     std::vector<double> x_old = x0;
//     std::vector<double> delta_x(n);
//     double delta;
//     delta = std::sqrt(x*x);
//     while(delta>tol){
//         x_old = x;
//         for(int i =0;i<n;i++){
//             x[i] = b[i] - (A*x)[i] + A(i, i)*x[i];
//             x[i] = x[i]/A(i, i);
//         }
//         delta_x = x-x_old;
//         delta = std::sqrt(delta_x*delta_x);
//     }
//     return x;
// }


std::vector <double> jacobi(const CSRMatrix& A, const std::vector <double>& b, const std::vector <double>& x0, double tol, int N){
    int n = b.size();
    std::vector<double> x = x0;
    std::vector<double> x_old = x0;
    std::vector<double> delta_x(n);
    double delta;
    int l=0;
    std::vector<double> r(n);
    delta = std::sqrt(x*x);
    while(delta>tol && l<N){
        //x_old = x;
        for(int i =0;i<n;i++){
            x[i] = b[i] - (A*x)[i] + A(i, i)*x[i];
            x[i] = x[i]/A(i, i);
        }
        //delta_x = x-x_old;
        //delta = std::sqrt(delta_x*delta_x); // - изменение вектора
        r = b - A*x; // невязка
        delta = sqrt(r*r); // норма невязки
        l++;
        std::cout<<l<< " "<<delta<< std::endl;
    }
    return x;
}
std::vector<double> gauss_zeidel(const CSRMatrix& A, const std::vector<double>& b, const std::vector<double>& x0,  double tol, int N){
    int n = b.size();
    int l=0;
    std::vector<double> x = x0;
    std::vector<double> x_old = x0;
    std::vector<double> delta_x(n);
    double delta;
    std::vector<double> r(n);
    double lu_sum = 0;
    delta = std::sqrt(x*x)+1;
    while (delta>tol && l<N){
        x_old = x;
        for(int i =0; i<n;i++){
            lu_sum = 0;
            for(int k = A.get_row()[i]; k<A.get_row()[i+1]; k++){
                if(A.get_col()[k]!=i){
                    lu_sum += A.get_values()[k]*x[A.get_col()[k]];
                }
            }
            x[i] = (b[i] -lu_sum)/A(i , i);
        }
        // delta_x = x-x_old;
        // delta = std::sqrt(delta_x*delta_x);
        r = b  -A*x;
        delta = sqrt(r*r);
        l++;
        std::cout<<l<< " "<<delta<< std::endl;
    }
    return x;
}
std::vector<double> mpi(const CSRMatrix& A, const std::vector<double>& b, const std::vector<double>& x0,  double tol, double tau, int N){
    int n = b.size();
    int l=0;
    std::vector<double> x = x0;
    std::vector<double> x_old = x0;
    std::vector<double> delta_x(n);
    std::vector<double> r(n);
    double delta=1;
    while(delta>tol && l<N){
        x_old = x;
        x = x - tau*(A*x-b);
        // delta_x = x-x_old;
        // delta = std::sqrt(delta_x*delta_x);
        l++;
        r = b - A*x;
        delta = sqrt(r*r);
        //std::cout<<l<< " "<<delta<< std::endl;
    }
    return x;

}

