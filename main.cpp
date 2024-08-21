#include "student.hpp"
#include "BellCurve.hpp"
#include <vector>
#include <iostream>
#include <numeric>
#include <iomanip>

int main() {
    std::vector<Student> students;
    int numStudents;

    std::cout << "How many students do you want to enter? ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        std::string name;
        int visaNote, finalNote;

        std::cout << "Enter name of student " << i + 1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Enter visa note for " << name << ": ";
        std::cin >> visaNote;

        std::cout << "Enter final note for " << name << ": ";
        std::cin >> finalNote;

        students.emplace_back(name, visaNote, finalNote);
    }

    double mu = 50.0;
    double sigma = 10.0;
    BellCurve bellCurve;

    double classAverage = std::accumulate(students.begin(), students.end(), 0.0,
        [](const double sum, const Student& student) {
            return sum + student.accountAverage();
        }) / students.size();

    std::cout << "\nClass Average: " << std::fixed << std::setprecision(2) << classAverage << std::endl;

    std::cout << "\nResults:\n";
    std::cout << std::left
              << std::setw(20) << "Student"
              << std::setw(12) << "Visa Note"
              << std::setw(12) << "Final Note"
              << std::setw(12) << "Average"
              << std::setw(15) << "Possibility"
              << "Status" << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    for (const auto& student : students) {
        double possibility = student.calculatePossibility(bellCurve, mu, sigma);
        std::cout << std::left
                  << std::setw(20) << student.name
                  << std::setw(12) << student.visaNote
                  << std::setw(12) << student.finalNote
                  << std::fixed << std::setprecision(2)
                  << std::setw(12) << student.accountAverage()
                  << std::scientific << std::setprecision(4)
                  << std::setw(15) << possibility
                  << (student.didPass(classAverage) ? "passed" : "failed")
                  << std::endl;
    }


    return 0;
}
