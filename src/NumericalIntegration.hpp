#pragma once

#include <tuple>
#include <algorithm>

namespace NumericalIntegration
{

/* Gaussian quadrature for 1 point (base, [-1, 1]) */
template <typename T, typename Function_1d>
constexpr T GaussianQuadrature_1p_1d_base(Function_1d &func);

/* Gaussian quadrature for 2 point (base, [-1, 1]) */
template <typename T, typename Function_1d>
constexpr T GaussianQuadrature_2p_1d_base(Function_1d &func);

/* Trapezoidal rule (base, [-1, 1]) */
template <typename T, typename Function_1d>
constexpr T Trapezoidal_1d_base(Function_1d &func);

/* Gaussian quadrature for 1 point (scaling, [left, right]) */
template <typename T, typename Function_1d>
constexpr T GaussianQuadrature_1p_1d_scaling(Function_1d &func, T left, T right);

/* Gaussian quadrature for 2 point (scaling, [left, right]) */
template <typename T, typename Function_1d>
constexpr T GaussianQuadrature_2p_1d_scaling(Function_1d &func, T left, T right);

} // namespace NumericalIntegration

#include <NumericalIntegration_template.hpp>
