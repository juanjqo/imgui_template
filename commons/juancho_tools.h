#pragma once

#include <Eigen/Dense>
#include <vector>
#include<cmath>

#ifdef _WIN32
#include <Eigen/Dense>
#else
#include <eigen3/Eigen/Dense>
#endif

using namespace Eigen;


class JuanchoTools
{
public:
    static std::vector<double> eigen_vector_to_stdvector(const VectorXd& v);
    static std::vector<double> linspace(const double& start, const double& end, const int& size);
};

