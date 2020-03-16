namespace NumericalIntegration
{

/* Gaussian quadrature for 1 point (base, [-1, 1]) */
template <typename T, typename Function_1d>
constexpr T GaussianQuadrature_1p_1d_base(Function_1d &func)
{
    return 2.0 * func(0.0);
}

/* Gaussian quadrature for 2 point (base, [-1, 1]) */
template <typename T, typename Function_1d>
constexpr T GaussianQuadrature_2p_1d_base(Function_1d &func)
{
    return func(-0.5773502691896258) + func(0.5773502691896258);
}

/* Trapezoidal rule (base, [-1, 1]) */
template <typename T, typename Function_1d>
constexpr T Trapezoidal_1d_base(Function_1d &func)
{
    return func(-1.0) + func(1.0);
}

} // namespace NumericalIntegration