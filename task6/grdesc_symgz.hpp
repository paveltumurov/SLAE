#include "../task4/Matrixes.hpp"
#include "../task4/v_ops.hpp"
#include <cmath>
#pragma once

std::vector<double> gradient_descent(const CSRMatrix& A, const std::vector<double>& b, const std::vector<double>& x0,  double tol, int N){
    int n = b.size();
    int l=0;
    std::vector<double> x = x0;
    std::vector<double> x_old = x0;
    std::vector<double> delta_x(n);
    std::vector<double> r(n);
    double tau;
    double delta=1;
    while(delta>tol && l<N){
        r = b - A*x;
        tau = (r*r)/(r*(A*r));
        x_old = x;
        x = x - tau*(A*x-b);
        l++;
        delta = sqrt(r*r);
        //std::cout<<l<< " "<<delta<< std::endl;
    }
    return x;
}
std::vector<double> symmetric_gz(const CSRMatrix& A, const std::vector<double>& b, const std::vector<double>& x0,  double tol, int N){
    int n = b.size();
    int l=0;
    std::vector<double> x = x0;
    std::vector<double> x_old = x0;
    std::vector<double> delta_x(n);
    double delta;
    std::vector<double> r(n);
    double lu_sum = 0;
    delta = std::sqrt(x*x)+1;
    while (!(delta<=tol && (l>=N))){
        for(int i =0; i<n;i++){
            lu_sum = 0;
            for(int k = A.get_row()[i]; k<A.get_row()[i+1]; k++){
                if(A.get_col()[k]!=i){
                    lu_sum += A.get_values()[k]*x[A.get_col()[k]];
                }
            }
            x[i] = (b[i] -lu_sum)/A(i , i);
        }
        for(int i = n-1; i>0;i--){
            lu_sum = 0;
            for(int k = A.get_row()[i]; k<A.get_row()[i+1]; k++){
                if(A.get_col()[k]!=i){
                    lu_sum += A.get_values()[k]*x[A.get_col()[k]];
                }
            }
            x[i] = (b[i] -lu_sum)/A(i , i);
        }
        r = b - A*x;
        delta = sqrt(r*r);
        l++;
        //std::cout<<l<< " "<<delta<< std::endl;
    }
    return x;
}