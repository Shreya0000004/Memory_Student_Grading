#include "sg_memory.h"

Student::Student(const std::string& n, int studentId, double studentMarks, int studentAge, const std::string& studentMajor, const std::string& studentMinor)
    : name(n), id(studentId), marks(studentMarks), age(studentAge), major(studentMajor), minor(studentMinor) {
    // Constructor implementation
}

std::string Student::getName() const {
    return name;
}

int Student::getID() const {
    return id;
}

double Student::getMarks() const {
    return marks;
}

int Student::getAge() const {
    return age;
}

std::string Student::getMajor() const {
    return major;
}

std::string Student::getMinor() const {
    return minor;
}

char Student::getGrade() const {
    if (marks >= 98) {
        return 'A';
    } else if (marks >= 94) {
        return 'A';
    } else if (marks >= 90) {
        return 'A';
    } else if (marks >= 80) {
        return 'B';
    } else if (marks >= 70) {
        return 'C';
    } else if (marks >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

bool Student::eligibility() const {
    return age >= 18 && age <= 21 && marks >= 45 && (major != "None" || minor != "None");
}

bool isNumeric(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

double calculateAverage(const std::vector<double>& courseMarks) {
    if (courseMarks.empty()) {
        return 0.0; // Return 0 if there are no courses
    }

    double sum = 0.0;
    for (double mark : courseMarks) {
        sum += mark;
    }

    return sum / courseMarks.size();
}

