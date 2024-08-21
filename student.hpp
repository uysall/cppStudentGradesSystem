#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include "BellCurve.hpp"

class Student {
public:
    std::string name;
    int visaNote;
    int finalNote;

    Student(std::string name, const int visaNote, const int finalNote)
        : name(std::move(name)), visaNote(visaNote), finalNote(finalNote) {}

    [[nodiscard]] double accountAverage() const {
        return (visaNote * 0.4 + finalNote * 0.6);
    }

    [[nodiscard]] bool didPass(double classAverage) const {
        return accountAverage() >= classAverage;
    }

    [[nodiscard]] double calculatePossibility(const BellCurve& bellCurve, double mu, double sigma) const {
        return bellCurve.calculateExponent(accountAverage(), mu, sigma);
    }
};

#endif // STUDENT_HPP