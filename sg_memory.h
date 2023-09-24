#ifndef SG_MEMORY_H
#define SG_MEMORY_H

#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int id;
    double marks;
    int age;
    std::string major;
    std::string minor;

public:
    // Constructor
    Student(const std::string& n, int studentId, double studentMarks, int studentAge, const std::string& studentMajor, const std::string& studentMinor);
    
    // Getter methods
    std::string getName() const;
    int getID() const;
    double getMarks() const;
    int getAge() const;
    std::string getMajor() const;
    std::string getMinor() const;

    // Grade calculation
    char getGrade() const;

    // Eligibility check
    bool eligibility() const;
};

bool isNumeric(const std::string& str);
double calculateAverage(const std::vector<double>& courseMarks);

#endif

