#ifndef BELL_CURVE_HPP
#define BELL_CURVE_HPP

#include <cmath>

class BellCurve {
public:
    [[nodiscard]] double calculateCoefficient(const double sigma) const {
        return 1 / (sigma * std::sqrt(2 * M_PI));
    }

    [[nodiscard]] double calculateExponent(const double x, const double mu, const double sigma) const {// çan eğrsindeki bilimsel terimleri parametrelerini alır
        const double coefficient = calculateCoefficient(sigma);
        const double exponent = -std::pow(x - mu, 2) / (2 * std::pow(sigma, 2));
        return coefficient * std::exp(exponent);
    }
};

#endif // BELL_CURVE_HPP
