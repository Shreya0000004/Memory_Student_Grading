/*
I used dynamic memory allocation to create `Student` objects on the heap rather than the stack. Dynamic memory allocation helps allocate memory for objects during the program's runtime and manage their lifetime explicitly. Here's a detailed explanation of the concepts involved:

 1. Dynamic Memory Allocation:
    - Dynamic memory allocation is a process of allocating memory during a program's runtime rather than at compile time.
    - It is done using operators like `new` (for allocation) and `delete` (for deallocation) in C++.

 2. Pointer to Objects:
    - Instead of creating `Student` objects directly on the stack (as in your original code), pointers are created to `Student` objects on the heap.
    - Each student is represented by a `Student*` (pointer to a `Student`) variable.

 3. `new` Operator:
    - The `new` operator is used to allocate memory for a `Student` object on the heap. For example:
      cpp
      Student* student = new Student(name, id, averageMarks, age, major, minor);
    - This line creates a new `Student` object on the heap and assigns its address to the `student` pointer.

 4. Vector of Pointers:
    - `std::vector<Student*>` is used to store these pointers to `Student` objects.
    - This vector acts as a dynamic collection of students, and each element is a pointer to a dynamically allocated `Student` object.

 5. Accessing Dynamic Objects:
    - To access members of dynamic objects, the arrow operator is used (`->`) with the pointers. For example:
      cpp
      student->getName();
      student->getAge();

 6. Deallocation with `delete`:
    - It's essential to deallocate memory when dynamic objects are no longer needed to prevent memory leaks.
    - the `delete` operator is used in a loop to release the memory for each dynamically allocated `Student` object:
      cpp
      for (Student* student : students) {
          delete student;
      }
     

 Here's how the dynamic memory allocation process works in this code:

 - For each student, memory is allocated on the heap using `new`, creating a dynamic `Student` object.
 - The pointer to this dynamic object is stored in the `students` vector.
 - After we're done using the objects (e.g., after displaying their information), to iterate through the vector and use `delete` to release the memory for each dynamic object.
 - This ensures that there's no memory leaks, as we explicitly free the memory allocated for each `Student` object.

 Using dynamic memory allocation in this way allowed me to manage multiple `Student` objects more flexibly and efficiently, especially when the number of students is not known at compile time.
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

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
    Student(const std::string& n, int studentId, double studentMarks, int studentAge, const std::string& studentMajor, const std::string& studentMinor)
        : name(n), id(studentId), marks(studentMarks), age(studentAge), major(studentMajor), minor(studentMinor) {}

    // Getter methods
    std::string getName() const {
        return name;
    }

    int getID() const {
        return id;
    }

    double getMarks() const {
        return marks;
    }

    int getAge() const {
        return age;
    }

    std::string getMajor() const {
        return major;
    }

    std::string getMinor() const {
        return minor;
    }

    // Grade calculation
    char getGrade() const {
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

    // Eligibility check
    bool eligibility() const {
        return age >= 18 && age <= 21 && marks >= 45 && (major != "None" || minor != "None");
    }
};

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

