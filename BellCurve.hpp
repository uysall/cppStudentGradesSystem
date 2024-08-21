#ifndef BELL_CURVE_HPP
#define BELL_CURVE_HPP

#include <cmath>

class BellCurve {
public:
    [[nodiscard]] double calculateCoefficient(double sigma) const {
        return 1 / (sigma * std::sqrt(2 * M_PI));
    }

    [[nodiscard]] double calculateExponent(double x, double mu, double sigma) const {
        double coefficient = calculateCoefficient(sigma);
        double exponent = -std::pow(x - mu, 2) / (2 * std::pow(sigma, 2));
        return coefficient * std::exp(exponent);
    }
};

#endif // BELL_CURVE_HPP
