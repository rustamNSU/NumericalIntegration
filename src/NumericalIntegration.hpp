#pragma once

#include <tuple>
#include <algorithm>

namespace NumericalIntegration
{
/* Gaussian quadrature for 1 point (base, [-1, 1]) */
template <typename T, typename Function_1d>
constexpr T GaussianQuadrature_1p_1d_base(Function_1d func);

/* Gaussian quadrature for 2 point (base, [-1, 1]) */
template <typename T, typename Function_1d>
constexpr T GaussianQuadrature_2p_1d_base(Function_1d func);
} // namespace NumericalIntegration

#include <NumericalIntegration_template.hpp>
