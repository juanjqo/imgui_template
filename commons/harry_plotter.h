#pragma once
#include "imgui.h"
#include "implot.h"
#include <cmath>
#include <vector>
#include <iostream>
#include <Eigen/Dense>

#ifdef _MSC_VER
#define sprintf sprintf_s
#endif

using namespace Eigen;

class HarryPlotter
{
protected:
    float span_;
    std::vector<ImVector<ImVec2>> data_;
    int size_of_points_;
public:
    enum TYPE
    {
        STATIC_BACKGROUND,
        DYNAMIC_BACKGROUND,
    };
    HarryPlotter(const int& size_of_points = 1,
                 const int& max_size = 2000,
                 const float& span = 10.0f);

    void add_point(const int& index_point,
                   const float& x, const float& y);
    void add_points(const float& x, const VectorXd& q);
    void plot_data(const std::string& name,
                   const float& time,
                   const std::vector<std::string> tags,
                   const float& history,
                   const std::tuple<float, float> yaxis_limits,
                   const ImPlotAxisFlags& flags,
                   const TYPE& type);
};


