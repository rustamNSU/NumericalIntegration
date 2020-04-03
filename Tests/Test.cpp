// #define _USE_MATH_DEFINES
#include "gtest/gtest.h"
#include "Test.hpp"
#include "NumericalIntegration.hpp"
#include <iostream>
#include <tuple>
#include <cmath>
#include <array>

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

    constexpr double r1 = NumericalIntegration::GaussianQuadratureBasic<0>(polynomial_2);
    EXPECT_DOUBLE_EQ(r1, 0.0);

    constexpr double r2 = NumericalIntegration::GaussianQuadratureBasic<1>(polynomial_2);
    EXPECT_DOUBLE_EQ(r2, 2.0 / 3.0);

    constexpr auto lambda_7 = [](double x)
    {
        return my_pow(x, 7) - 10 * my_pow(x, 5) - 2;
    };
    constexpr double r3 = NumericalIntegration::GaussianQuadratureBasic<3>(lambda_7, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(r3, -(7733.0 / 24.0));
}

TEST(NumericalIntegrationTest, GaussianQuadrature)
{
    constexpr auto lambda_11 = [](double x)
    {
        return my_pow(x, 11);
    };

    constexpr size_t n = 6;
    constexpr size_t nPoint = 2;

    constexpr std::array<double, n> result
    {
        NumericalIntegration::GaussianQuadrature<nPoint>(lambda_11, 0.0, 2.0, 1),
        NumericalIntegration::GaussianQuadrature<nPoint>(lambda_11, 0.0, 2.0, 2),
        NumericalIntegration::GaussianQuadrature<nPoint>(lambda_11, 0.0, 2.0, 4),
        NumericalIntegration::GaussianQuadrature<nPoint>(lambda_11, 0.0, 2.0, 8),
        NumericalIntegration::GaussianQuadrature<nPoint>(lambda_11, 0.0, 2.0, 16),
        NumericalIntegration::GaussianQuadrature<nPoint>(lambda_11, 0.0, 2.0, 32)
    };
    std::cout.width(20);
    std::cout << std::left << "Edges number" << "Absolute error" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout.width(20);
        std::cout << std::left << std::pow(2, i) << result[i] - 1024.0 / 3.0 << std::endl;
    }
}