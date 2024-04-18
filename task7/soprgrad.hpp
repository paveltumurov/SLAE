#include "../task4/Matrixes.hpp"
#include "../task4/v_ops.hpp"
#include <cmath>
std::vector<double> conj_grad(const CSRMatrix& A, const std::vector<double>& b, const std::vector<double>& x0,  double tol, int N){
    int n = b.size();
    int l=0;
    std::vector<double> x = x0;
    std::vector<double> x_old = x0;
    std::vector<double> delta_x(n);
    std::vector<double> r(n), r_new(n);
    double alpha, beta;
    double delta=1;
    std::vector<double> d = A*x-b;
    while(!(delta<=tol) && l<N){
        r = A*x-b;
        alpha = (r*r)/(d*(A*d));
        x = x-alpha*d;
        r_new = A*x-b;
        beta = (r_new*r_new)/(r*r);
        d = beta*d + r_new;
        delta = std::sqrt(r_new*r_new);
    }
    return x;
}
