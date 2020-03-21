// #define _USE_MATH_DEFINES
#include "gtest/gtest.h"
#include "Test.hpp"
#include "NumericalIntegration.hpp"
#include <iostream>

constexpr double test_func(double x)
{
    return x*x;
}

TEST(NumericalIntegrationUnitTest, GaussianQuadratureBase)
{
    EXPECT_DOUBLE_EQ(0.0, NumericalIntegration::GaussianQuadrature_1p_1d_base<double>(test_func));

    constexpr double test_2p = NumericalIntegration::GaussianQuadrature_2p_1d_base<double>(test_func);
    std::cout << NumericalIntegration::GaussianQuadrature_2p_1d_base<int>(test_func) << std::endl
              << NumericalIntegration::GaussianQuadrature_2p_1d_base<double>(test_func);

    EXPECT_DOUBLE_EQ(2.0 / 3.0, test_2p);
    EXPECT_DOUBLE_EQ(2.0, NumericalIntegration::Trapezoidal_1d_base<double>(test_func));
}

TEST(NumericalIntegrationUnitTest, LambdaAsFunction)
{
    auto test_lambda = [](double x) constexpr
    { 
        return (x+1)*x*x; 
    };

    EXPECT_DOUBLE_EQ(0.0, NumericalIntegration::GaussianQuadrature_1p_1d_base<double>(test_lambda));

    constexpr double test_2p = NumericalIntegration::GaussianQuadrature_2p_1d_base<double>(test_lambda);
    EXPECT_DOUBLE_EQ(2.0 / 3.0, test_2p);
    EXPECT_DOUBLE_EQ(2.0, NumericalIntegration::Trapezoidal_1d_base<double>(test_lambda));
}

TEST(NumericalIntegrationUnitTest, GaussianQuadratureScaling)
{
    EXPECT_DOUBLE_EQ(2.25, NumericalIntegration::GaussianQuadrature_1p_1d_scaling(test_func, 1.0, 2.0));
    EXPECT_DOUBLE_EQ(2.25, NumericalIntegration::GaussianQuadrature_1p_1d_scaling(test_func, 1.0, 2.0));
    EXPECT_DOUBLE_EQ(2.0, NumericalIntegration::Trapezoidal_1d_base<double>(test_func));
}