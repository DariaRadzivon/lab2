#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

class Student {
private:
    string lastName;
    string recordBookNumber;
    vector<int> grades;

public:
    // Default constructor
    Student() {
        lastName = "";
        recordBookNumber = "";
        grades = {};
    }

    // Constructor with parameters
    Student(string lastName, string recordBookNumber, vector<int> grades) {
        this->lastName = lastName;
        this->recordBookNumber = recordBookNumber;
        this->grades = grades;
    }

    // Method to get the student's last name
    string getLastName() const {
        return lastName;
    }

    // Method to calculate the student's average grade
    double getAverageGrade() const {
        int sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return static_cast<double>(sum) / grades.size();
    }

    // Method to display student information
    void show() const {
        cout << "Прізвище: " << lastName << ", Залікова книжка: " << recordBookNumber << ", Оцінки: ";
        for (int grade : grades) {
            cout << grade << " ";
        }
        cout << ", Середній бал: " << getAverageGrade() << endl;
    }
};

class Group {
private:
    vector<Student> students;

public:
    // Method to add a student to the group
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Method to display all students
    void showAllStudents() const {
        cout << "Всі студенти:" << endl;
        for (const Student& student : students) {
            student.show();
        }
    }

    // Method to display the top students by average grade
    void showTopStudents(int topCount) const {
        // Sorting students by average grade
        vector<Student> sortedStudents = students;
        sort(sortedStudents.begin(), sortedStudents.end(), [](const Student& a, const Student& b) {
            return a.getAverageGrade() > b.getAverageGrade();
            });

        // Displaying the top students
        cout << "Топ " << topCount << " студентів за середнім балом:" << endl;
        for (int i = 0; i < topCount && i < sortedStudents.size(); ++i) {
            sortedStudents[i].show();
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    // Creating a group
    Group group;

    // Adding students
    group.addStudent(Student("Петренко", "54321", { 78, 82, 80 }));
    group.addStudent(Student("Хрущ", "14075", { 90, 85, 92 }));
    group.addStudent(Student("Гуда", "23061", { 90, 100, 84 }));
    group.addStudent(Student("Сидоренко", "67890", { 85, 88, 91 }));
    group.addStudent(Student("Коваль", "98765", { 95, 94, 93 }));
    group.addStudent(Student("Гнатюк", "11111", { 89, 90, 88 }));
    group.addStudent(Student("Ткаченко", "28741", { 69, 67, 78 }));
    group.addStudent(Student("Дзвоник", "95281", { 69, 54, 84 }));

    // Displaying all students
    group.showAllStudents();

    // Displaying the top 5 students by average grade
    group.showTopStudents(5);

    return 0;
}
