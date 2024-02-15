#include <vector>
class TDM
{
public:
    TDM (std::vector<double>& low, std::vector<double>& maind,std::vector<double>& high)
    {
        low_diag = low;
        main_diag  = maind;
        high_diag = high;
        
    }
    std::vector<double> solution(std::vector<double> f);  
    std::vector <double> low_diag;
    std::vector <double> main_diag;
    std::vector <double> high_diag;
};