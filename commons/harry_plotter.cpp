#include "harry_plotter.h"




HarryPlotter::HarryPlotter(const int& size_of_points, const TYPE &type,
                           const int &max_size,
                           const float &span)
    :span_(span),size_of_points_(size_of_points),maxsize(max_size)
{
    ImVector<ImVec2> data;
    data_ = std::vector<ImVector<ImVec2>>(size_of_points, data);
    for (auto &element : data_)
    {
        element.reserve(max_size);
    }
    if (type == TYPE::DYNAMIC_BACKGROUND)
    {
        dynamic_background_ = true;

    }else{
        dynamic_background_ = false;
    }
    yaxis_limits_ = {-2*M_PI, 2*M_PI};
    //offset_  = 0;
    offsets_ = std::vector<int>(size_of_points, 0);
}

/**
 * @brief HarryPlotter::add_point
 * @param index_point
 * @param x
 * @param y
 */
void HarryPlotter::add_point(const float& x, const float& y, const int& index_point)
{
    if (index_point > size_of_points_)
    {
        std::cerr<<"The index point is higher than "<<size_of_points_<<std::endl;
    }
    else
    {
        if (!dynamic_background_) //static background
        {
            float xmod = fmodf(x, span_);
            if (!data_.at(index_point).empty() && xmod < data_.at(index_point).back().x)
                data_.at(index_point).shrink(0);
            data_[index_point].push_back(ImVec2(xmod, y));
        }
        else{  //dynamic background
            if (data_.at(index_point).size() < maxsize)
            {
                data_.at(index_point).push_back(ImVec2(x,y));
            }
            else {
                data_.at(index_point)[offsets_.at(index_point)] = ImVec2(x,y);
                offsets_.at(index_point) =  (offsets_.at(index_point) + 1) % maxsize;

            }
        }
    }
}


/**
 * @brief HarryPlotter::add_points
 * @param x
 * @param q
 */
void HarryPlotter::add_points(const float &x, const VectorXd &q)
{
    _check_size(q);
    for (int i=0; i<q.size();i++)
    {
        add_point(x, q[i], i);
    }

}


void HarryPlotter::plot_data(const std::string &name, const float &time,
                             const float &history,
                             const ImPlotAxisFlags &flags)
{
    float yaxis_min;
    float yaxis_max;

    if (tags_.empty())
    {
        tags_ = std::vector<std::string>(size_of_points_, "");
    }

    if (ImPlot::BeginPlot(name.c_str(), ImVec2(-1, vertical_plot_size_))) {
        ImPlot::SetupAxes(nullptr, nullptr, flags, flags);
        if (!dynamic_background_)
        {
            ImPlot::SetupAxisLimits(ImAxis_X1,0,history, ImGuiCond_Always);
            _set_span(history);
        }
        else
        {
            ImPlot::SetupAxisLimits(ImAxis_X1, time - history, time, ImGuiCond_Always);
            //ImPlot::SetNextFillStyle(IMPLOT_AUTO_COL,0.5f);
        }
        std::tie(yaxis_min, yaxis_max) = yaxis_limits_;
        ImPlot::SetupAxisLimits(ImAxis_Y1,yaxis_min ,yaxis_max, ImGuiCond_Always);
        for (int i=0; i<size_of_points_; i++)
        {
            ImPlot::PlotLine(tags_.at(i).c_str(),
                             &data_.at(i)[0].x,
                             &data_.at(i)[0].y,
                             data_.at(i).size(),
                             0, offsets_.at(i), 2 * sizeof(float));
        }

        ImPlot::EndPlot();
    }
}

void HarryPlotter::set_tags(const std::vector<std::string> tags)
{
    _check_size(tags);
    tags_ = tags;
}

void HarryPlotter::set_yaxis(const std::tuple<float, float> yaxis_limits)
{
    yaxis_limits_ = yaxis_limits;
}

void HarryPlotter::set_vertical_plot_size(const float &size)
{
    vertical_plot_size_ = size;
}

void HarryPlotter::_set_span(const float &span)
{
    span_= span;
}

/*
void HarryPlotter::Erase()
{
    for ( auto&v : data_)
    {
    if (v.size() > 0) {
        v.shrink(0);
        offset_  = 0;
    }
    }

}*/
