#include <vector>
#include <iostream>
class Dense_matrix{
public:
    Dense_matrix(const std::vector<double>& a, unsigned int m, unsigned int n){
        matrix = a;
        rows = m;
        cols = n;
    };
    double operator()(unsigned int i, unsigned int j) const;
    unsigned int col() const;//return cols
    unsigned int row() const;//return rows
    void show();// shows matrix
    std::vector<double> operator* (const std::vector<double>& b) const;//matrix*vector
    Dense_matrix operator+ (const Dense_matrix& b) const;// matrix+matrix
    Dense_matrix operator- (const Dense_matrix& b) const;//matrix-matrix
    Dense_matrix operator*(const double& a) const;//matrix*number
    std::vector<double> get_values() const;
private:
    int rows, cols;
    std::vector<double> matrix;
};

class CSRMatrix{
public:
    CSRMatrix(const std::vector<double>& vals, const std::vector<double>& c, const std::vector<double>& r,unsigned int a, unsigned int b){
        values = vals;
        col = c;
        row = r;
        rows = a;
        cols = b;
    };
    std::vector<double> operator* (const std::vector<double>& b) const;//matrix*vector
    double operator()(unsigned int i, unsigned int j) const;//ij element
    CSRMatrix operator*(const double& a) const;//matrix*number
    void show(){
        for (int i = 0; i<rows;i++){
            for (int j = 0; j<cols; j++){
            std::cout<< (*this)(i, j)<<" ";
            }
            std::cout<<std::endl;
        }
    }
    unsigned int get_cols() const{
        return cols;
    }
    std::vector<double> get_col() const{
        return col;
    }
    std::vector<double> get_row() const{
        return row;
    }
    std::vector<double> get_values() const{
        return values;
    }
private:
    std::vector<double> values, row, col;
    unsigned int cols, rows;
};
