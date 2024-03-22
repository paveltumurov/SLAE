#include "iterations.hpp"
#pragma once
int deg2(int n){
    int k=1;
    for (int i =0; i<n;i++)
    {
        k *= 2;
    }
    return(k);
}
std::vector <int> rearrange(int r){
    int N=deg2(r);
    std::vector<int> new_indexes(N);
    int n = N;
    new_indexes[0] = 0;
    int p=2;
    new_indexes[N/2] = 1;
    for (int i=1; i<r;i++){
        n/=2;
        p*=2;
        for (int j = 0; j < N; j+=n) {
                new_indexes[j+n/2] = p - 1 - new_indexes[j];
            }
    }
    return new_indexes;
}
std::vector<double> cheb_mpi(const CSRMatrix& A, const std::vector<double>& b, const std::vector<double>& x0,  double tol, double lambda_min, double lambda_max, int R){
    int n = b.size();
    int N=deg2(R);
    int l=0;
    std::vector<double> x = x0;
    std::vector<double> x_old = x0;
    std::vector<double> delta_x(n);
    std::vector<double> r(n);
    std::vector<double> tau(N);
    std::vector<int> new_ind = rearrange(R);
    double delta=1;
    for (int i =0;i<N;i++){
        tau[new_ind[i]] = 1/((lambda_max+lambda_min)/2+(lambda_max-lambda_min)/2*cos(pi*(2*l+1)/2/n));
    }
    while(delta>tol && l<N){
        x_old = x;
        x = x - tau[l]*(A*x-b);
        l++;
        r = b - A*x;
        delta = sqrt(r*r);
        //std::cout<<l<< " "<<delta<< std::endl;
    }
    return x;
}