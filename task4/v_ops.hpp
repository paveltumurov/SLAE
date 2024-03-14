#include <vector>
#include <iostream>
double operator* (const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator* (double a, const std::vector<double>& b);
std::vector<double> operator+ (const std::vector<double>& a, const std::vector<double>& b);
std::vector<double> operator- (const std::vector<double>& a, const std::vector<double>& b);
void show(const std::vector<double>& v);
