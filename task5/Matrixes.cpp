#include "Matrixes.hpp"
double Dense_matrix::operator()(unsigned int i, unsigned int j) const
{
    return matrix[cols*i+j];
}
unsigned int Dense_matrix::col() const{
    return cols;
}
unsigned int Dense_matrix::row() const{
   return rows;
}
void Dense_matrix::show(){
    for (unsigned int i =0; i<rows; i++){
        for(unsigned int j = 0; j<cols; j++){
            std::cout<<(*this)(i, j)<<" ";
        }
        std::cout<<std::endl;
    }
}
std::vector<double> Dense_matrix::operator* (const std::vector<double>& b) const{
    std::vector<double> x(this->rows, 0);
    for (unsigned int i = 0; i<this->rows;i++){
        for(unsigned int j = 0; j<this->cols; j++)
        {
            x[i] += (*this)(i, j)*b[j];
        }
    }

    return x;
}
Dense_matrix Dense_matrix::operator+ (const Dense_matrix& b) const{
    std::vector<double> c(rows*cols);
    for (int i = 0; i<cols; i++){
        for (int j = 0; j<rows; j++){
            c[i*rows+j] = (*this)(j, i) + b(j, i);
        }
    }
    Dense_matrix C(c, this->rows, this->cols);
    return C;
};
Dense_matrix Dense_matrix::operator- (const Dense_matrix& b) const{
    std::vector<double> c(rows*cols);
    for (int i = 0; i<cols; i++){
        for (int j = 0; j<rows; j++){
            c[i*rows+j] = (*this)(j, i) - b(j, i);
        }
    }
    Dense_matrix C(c, this->rows, this->cols);
    return C;
}
Dense_matrix Dense_matrix::operator*(const double& a) const {
    std::vector<double> c(rows*cols);
    for (int i = 0; i<cols; i++){
        for (int j = 0; j<rows; j++){
            c[i*rows+j] = (*this)(j, i)*a;
        }
    }
    Dense_matrix C(c, this->rows, this->cols);
    return C;
}
std::vector<double> Dense_matrix::get_values() const{
	return matrix;
}


std::vector<double> CSRMatrix::operator* (const std::vector<double>& b) const {
    std::vector<double> res(rows, 0);
    for (auto i = 0; i < rows; i++) {
        for (auto j = row[i]; j < row[i+1]; j++) {
            res[i] += b[col[j]]*values[j];
        }
    }
    return res;
}
double CSRMatrix::operator()(unsigned int i, unsigned int j) const{
    double x;
    bool flag = true;
    unsigned int row_end, row_start;
    row_start = row[i];
    row_end = row[i+1];
    for (unsigned int k = row_start; k<= row_end; k++){
        if (col[k]==j && flag){
            x = values[k];
            flag = false;
        }
    }
    if(flag){
        x = 0;
    }
    return x;
}
CSRMatrix CSRMatrix::operator* (const double& a) const{
    std::vector<double> tmp(values.size());
    for (int i=0; i< values.size();i++){
        tmp[i] = values[i] * a;
    }
    CSRMatrix C(tmp, row, col, cols, rows);
    return C;
}
