#pragma once

#include <tuple>
#include <array>
#include <algorithm>

namespace NumericalIntegration
{
template <size_t size>
using row = std::array<double, size>;

using std::tuple;

constexpr tuple<row<1>,
                row<2>,
                row<3>,
                row<4>>
    GaussianQuadraturePoints
{
    {0.0},
    {-0.5773502691896258, 0.5773502691896258},
    {-0.7745966692414834, 0.0, 0.7745966692414834},
    {-0.8611363115940526, -0.3399810435848563, 0.3399810435848563, 0.8611363115940526}
};

constexpr tuple<row<1>,
                row<2>,
                row<3>,
                row<4>>
    GaussianQuadratureWeights
{
    {2.0},
    {1.0, 1.0},
    {0.5555555555555556, 0.8888888888888888, 0.5555555555555556},
    {0.3478548451374538, 0.6521451548625461, 0.6521451548625461, 0.3478548451374538}
};

template<size_t points_number>
constexpr double GetPoint(size_t index)
{
    return std::get<points_number>(GaussianQuadraturePoints)[index];
}

template<size_t points_number>
constexpr double GetWeight(size_t index)
{
    return std::get<points_number>(GaussianQuadratureWeights)[index];
}


template <size_t points_number, typename Function>
constexpr double GaussianQuadrature(
    Function &function, ///< Function or lambda-expression
    double left = -1.0,
    double right = 1.0)
{
    double result = 0.0;
    double mid_point = (left + right) / 2.0;
    double scaling_coef = (right - left) / 2.0;

    for (size_t i = 0; i <= points_number; ++i)
    {
        result += GetWeight<points_number>(i) * 
                  function(scaling_coef * GetPoint<points_number>(i) + mid_point);
    }

    return result * scaling_coef;
}




} // namespace NumericalIntegration