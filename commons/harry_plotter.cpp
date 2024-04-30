#include "harry_plotter.h"




HarryPlotter::HarryPlotter(const int& size_of_points,
                           const int &max_size,
                           const float &span)
    :span_(span),size_of_points_(size_of_points)
{
    ImVector<ImVec2> data;
    data_ = std::vector<ImVector<ImVec2>>(size_of_points, data);
    for (auto &element : data_)
    {
        element.reserve(max_size);
    }
}

/**
 * @brief HarryPlotter::add_point
 * @param index_point
 * @param x
 * @param y
 */
void HarryPlotter::add_point(const int &index_point, const float &x, const float &y)
{
    if (index_point > size_of_points_)
    {
        std::cerr<<"The index point is higher than "<<size_of_points_<<std::endl;
    }
    else
    {
        float xmod = fmodf(x, span_);
        if (!data_[index_point].empty() && xmod < data_[index_point].back().x)
            data_[index_point].shrink(0);
        data_[index_point].push_back(ImVec2(xmod, y));
    }
}


/**
 * @brief HarryPlotter::add_points
 * @param x
 * @param q
 */
void HarryPlotter::add_points(const float &x, const VectorXd &q)
{
    if (q.size() > size_of_points_)
    {
        std::cerr<<"The index point is higher than "<<size_of_points_<<std::endl;
    }
    else
    {
        for (int i=0; i<q.size();i++)
        {
            add_point(i, x, q[i]);
        }
    }
}


void HarryPlotter::plot_data(const std::string &name, const float &time, const std::vector<std::string> tags,
                             const float &history,
                             const std::tuple<float, float> yaxis_limits,
                             const ImPlotAxisFlags &flags,
                             const TYPE &type)
{
    float yaxis_min;
    float yaxis_max;
    std::tie(yaxis_min, yaxis_max) = yaxis_limits;

    if (ImPlot::BeginPlot(name.c_str(), ImVec2(-1,150))) {
        ImPlot::SetupAxes(nullptr, nullptr, flags, flags);
        if (type == TYPE::STATIC_BACKGROUND)
            ImPlot::SetupAxisLimits(ImAxis_X1,0,history, ImGuiCond_Always);
        else
            ImPlot::SetupAxisLimits(ImAxis_X1, time - history, time, ImGuiCond_Always);
        ImPlot::SetupAxisLimits(ImAxis_Y1,yaxis_min ,yaxis_max, ImGuiCond_Always );

        for (int i=0; i<size_of_points_; i++)
        {
            ImPlot::PlotLine(tags.at(i).c_str(),
                             &data_.at(i)[0].x,
                             &data_.at(i)[0].y,
                             data_.at(i).size(),
                             0, 0, 2 * sizeof(float));
        }

        ImPlot::EndPlot();
    }
}
