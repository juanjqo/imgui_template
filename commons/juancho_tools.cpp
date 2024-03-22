#include "juancho_tools.h"


std::vector<double> JuanchoTools::eigen_vector_to_stdvector(const VectorXd& v)
{
    std::vector<double> vec;
    vec.resize(v.size());
    Eigen::Map<VectorXd>(vec.data(), vec.size()) = v;
    return vec;
}

Eigen::VectorXd JuanchoTools::std_vector_to_eigen_vector(std::vector<double> &std_vector)
{
    return Eigen::Map<VectorXd>(std_vector.data(), std_vector.size());
}

std::vector<double> JuanchoTools::linspace(const double &start, const double &end, const int &size)
{

    VectorXd x = VectorXd::LinSpaced(size,start,end);
    //std::vector<double> vec;
    //vec.resize(x.size());
    //Eigen::Map<VectorXd>(vec.data(), vec.size()) = x;
    return eigen_vector_to_stdvector(x);
}
