// #define _USE_MATH_DEFINES
#include "gtest/gtest.h"
#include "Test.hpp"
#include "NumericalIntegration.hpp"
#include <iostream>
#include <tuple>
#include <cmath>

constexpr double polynomial_2(double x)
{
    return x * x;
}

constexpr double my_pow(double x, size_t power)
{
    double result = 1.0;
    for (size_t i = 0; i < power; ++i)
    {
        result *= x;
    }
    return result;
}

TEST(NumericalIntegrationUnitTest, GaussianQuadrature)
{
    constexpr double a = std::get<3>(NumericalIntegration::GaussianQuadraturePoints)[0];
    constexpr double b = NumericalIntegration::GetPoint<3>(0);
    EXPECT_DOUBLE_EQ(a, b);

    constexpr double r1 = NumericalIntegration::GaussianQuadrature<0>(polynomial_2);
    EXPECT_DOUBLE_EQ(r1, 0.0);

    constexpr double r2 = NumericalIntegration::GaussianQuadrature<1>(polynomial_2);
    EXPECT_DOUBLE_EQ(r2, 2.0 / 3.0);

    constexpr auto lambda_7 = [](double x)
    {
        return my_pow(x, 7) - 10 * my_pow(x, 5) - 2;
    };
    constexpr double r3 = NumericalIntegration::GaussianQuadrature<3>(lambda_7, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(r3, -(7733.0 / 24.0));
    
}