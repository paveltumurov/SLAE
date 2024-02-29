#include <vector>
#include "Matrixes.hpp"
#include "v_ops.hpp"
#include <cmath>

std::pair<Dense_matrix, Dense_matrix> QR_HH(const Dense_matrix& A){
    unsigned int n;
    n = A.col();
    std::vector<std::vector<double>> vecs(n);
    std::vector<double> r_values(n*n);
    r_values = A.get_values();
    for(int i=0; i<n; i++)
    {
        std::vector<double> v(n-i);
        std::vector<double> x(n-i);
        
        for (int j = 0; j<n-i;j++)
        {
            v[j] = r_values[(j+i)*n+ i];
        }
        if (v[0]*A(i,i)>=0){
            v[0]+=std::sqrt(v*v);
        }
        else{
            v[0]-=std::sqrt(v*v);
        };//made vector v
        vecs[i] = v;//saving vector v;
        for(int j = 0; j<n-i;j++)
        {
            for(int k =0; k<n-i;k++){
                x[k] = r_values[(k+i)*n+ j+i];
            }//made vector x(столбец)
            double c = -2*(v*x)/(v*v);
            for(int k = 0; k<n-i;k++){
                r_values[(k+i)*n+j+i] = x[k]+c*v[k];
            }
            // Dense_matrix R_(r_values, n, n);
            // R_.show();
            // std::cout<<std::endl;

        }
    }
    Dense_matrix R(r_values, n,n);
//////////////////////////////////////////////////////////
    //Q
    std::vector<double> q_values(n*n, 0);
    for(int i =0;i<n;i++){
        q_values[i*n+i] = 1;
    }
    std::vector<double> x(n);//строка
    for (int i=0;i<n-1;i++)
    {
        for(unsigned int j=0; j<n;j++)
        {
            for (unsigned int k=0;k<n-i;k++)
            {
                x[k] = q_values[j*n+k+i];
            }//made vector x(строка)
            double c =  -2*(vecs[i]*x)/(vecs[i]*vecs[i]);
            for (unsigned int k=0;k<n-i;k++)
            {
                q_values[j*n+k+i] = x[k]+c*vecs[i][k];
            }
        }
    }
    Dense_matrix Q(q_values, n,n);

    return std::pair(Q,R);
}
std::vector<double> QR_solver(const Dense_matrix& A, const std::vector<double>& b) {
    std::pair<Dense_matrix, Dense_matrix> q_r = QR_HH(A);
    int n = q_r.first.col();
    std::vector<double> q_values = q_r.first.get_values();
    std::vector<double> qt_values(n*n);
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            qt_values[j*n+i] = q_values[i*n+j];
        }
    }
    Dense_matrix QT(qt_values, n, n);
    std::vector<double> x(n);
    x = QT * b;
    //show(x);
    x[n-1] /= (q_r.second)(n-1,n-1);
    for(int i =n-2;i>=0;i--){
        for(int j = i+1; j<n;j++){
            x[i] -= x[j]*(q_r.second)(i, j);
        }
        x[i] = x[i]/(q_r.second)(i,i);
    }
    return x;
}
int main()
{
    std::vector<double> f={1,2,3,4,5,6,7,8,10};
    Dense_matrix A(f,3,3);
    std::vector<double> b = {1,2,3};
    show(QR_solver(A, b));
}


