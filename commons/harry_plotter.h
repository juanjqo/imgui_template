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
    int offset_;
    bool dynamic_background_ = false;
    int maxsize;
    std::vector<std::string> tags_;
    std::tuple<float, float> yaxis_limits_;
    void _set_span(const float& span);

    float vertical_plot_size_ = 150;

    template<typename T>
    void _check_size(const T& v)
    {
        if (v.size() != size_of_points_)
        {
            std::cerr<<"Wrong vector size. The vector must have a size of "<<size_of_points_<<std::endl;
        }
    }

public:
    enum TYPE
    {
        STATIC_BACKGROUND,
        DYNAMIC_BACKGROUND,
    };
    HarryPlotter(const int& size_of_points = 1,
                 const TYPE& type = TYPE::STATIC_BACKGROUND,
                 const int& max_size = 2000,
                 const float& span = 10.0f);

    void add_point(const float& x, const float& y,const int& index_point=0);
    void add_points(const float& x, const VectorXd& q);
    void plot_data(const std::string& name,
                   const float& time,
                   const float& history,
                   const ImPlotAxisFlags& flags = ImPlotAxisFlags_NoTickLabels);

    void set_tags(const std::vector<std::string> tags);
    void set_yaxis(const std::tuple<float, float> yaxis_limits);
    void set_vertical_plot_size(const float& size);

    void Erase();
};


