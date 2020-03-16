// #define _USE_MATH_DEFINES
#include "gtest/gtest.h"
#include "Test.hpp"
#include "NumericalIntegration.hpp"

constexpr double test_func(double x)
{
    return x*x;
}

TEST(NumericalIntegrationUnitTest, GaussianQuadratureBase)
{
    double eps = 1e-8;

    EXPECT_DOUBLE_EQ(0.0, NumericalIntegration::GaussianQuadrature_1p_1d_base<double>(test_func));
    EXPECT_DOUBLE_EQ(4.0 / 3.0, NumericalIntegration::GaussianQuadrature_2p_1d_base<double>(test_func));
}