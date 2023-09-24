#include <iostream>
#include <string>
#include <vector>
#include "sg_memory.h"

int main() {
    int numStudents;

    std::cout << "Enter the number of students: ";
    std::string numStudentsStr;
    std::getline(std::cin, numStudentsStr);
    if (!isNumeric(numStudentsStr)) {
        std::cerr << "Error: Invalid number of students input." << std::endl;
        return 1;
    }
    numStudents = std::stoi(numStudentsStr);

    std::vector<Student*> students;

    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Enter student " << i + 1 << "'s name: ";
        std::string studentName;
        while (true) {
            std::getline(std::cin, studentName);
            if (!studentName.empty()) {
                break;
            }
            std::cout << "Error: Student name cannot be empty. Please enter a valid name: ";
        }

        std::cout << "Enter student " << studentName << "'s ID: ";
        std::string idStr;
        std::getline(std::cin, idStr);
        if (!isNumeric(idStr)) {
            std::cerr << "Error: Invalid ID input." << std::endl;
            return 1;
        }
        int id = std::stoi(idStr);

        std::cout << "Enter student " << studentName << "'s age: ";
        std::string ageStr;
        std::getline(std::cin, ageStr);
        if (!isNumeric(ageStr)) {
            std::cerr << "Error: Invalid age input." << std::endl;
            return 1;
        }
        int age = std::stoi(ageStr);

        std::cout << "Enter student " << studentName << "'s major (options: computer science, economics, business, sciences, English literature, politics, history, None): ";
        std::string major;
        std::getline(std::cin, major);

        std::cout << "Enter student " << studentName << "'s minor (options: computer science, economics, business, sciences, English literature, politics, history, None): ";
        std::string minor;
        std::getline(std::cin, minor);

        std::cout << "Enter the number of courses taken by " << studentName << " (up to 7): ";
        std::string numCoursesStr;
        std::getline(std::cin, numCoursesStr);
        if (!isNumeric(numCoursesStr)) {
            std::cerr << "Error: Invalid number of courses input." << std::endl;
            return 1;
        }
        int numCourses = std::stoi(numCoursesStr);

        if (numCourses > 7) {
            std::cerr << "Error: Number of courses cannot be greater than 7." << std::endl;
            return 1;
        }

        std::vector<std::string> courses;
        std::vector<double> courseMarks;

        for (int j = 0; j < numCourses; ++j) {
            std::cout << "Enter name of course " << j + 1 << " for student " << studentName << ": ";
            std::string courseName;
            std::getline(std::cin, courseName);
            if (courseName.empty()) {
                std::cerr << "Error: Course name cannot be empty." << std::endl;
                return 1;
            }

            std::cout << "Enter mark for course " << courseName << " for student " << studentName << ": ";
            std::string courseMarkStr;
            std::getline(std::cin, courseMarkStr);
            if (!isNumeric(courseMarkStr)) {
                std::cerr << "Error: Invalid course mark input." << std::endl;
                return 1;
            }
            double courseMark = std::stod(courseMarkStr);

            courses.push_back(courseName);
            courseMarks.push_back(courseMark);
        }

        // Calculate the average of course marks
        double averageMarks = calculateAverage(courseMarks);

        // Create a Student object
        Student* student = new Student(studentName, id, averageMarks, age, major, minor);

        // Display student grade
        std::cout << "Grade for student " << studentName << ": " << student->getGrade() << std::endl;

        // Add the student to the vector
        students.push_back(student);
    }

    // Display student information and eligibility
    for (Student* student : students) {
        std::cout << "\nStudent Information:\n";
        std::cout << "Name: " << student->getName() << std::endl;
        std::cout << "ID: " << student->getID() << std::endl;
        std::cout << "Average Marks: " << student->getMarks() << std::endl;
        std::cout << "Age: " << student->getAge() << std::endl;
        std::cout << "Major: " << student->getMajor() << std::endl;
        std::cout << "Minor: " << student->getMinor() << std::endl;
        std::cout << "Grade: " << student->getGrade() << std::endl;

        // Check eligibility
        if (student->eligibility()) {
            std::cout << "Eligibility: PASSED!" << std::endl;
        } else {
            std::cout << "Eligibility: FAILED!" << std::endl;
        }
    }

    // Cleanup: Delete dynamically allocated Student objects
    for (Student* student : students) {
        delete student;
    }

    return 0;
}

