#include "students.h"
#include <iostream>
using namespace std;

int main() {
    int numOfStudents;
    Students* students = nullptr;

    cout << "Enter # of Students: " << endl;
    cin >> numOfStudents;

    if (numOfStudents > 0) {
        students = new Students[numOfStudents];
    }

    studentsData(students, numOfStudents);
    studentsInfo(students, numOfStudents);
    highScoreStudents(students, numOfStudents);
    saveToFile(students, numOfStudents);
    readFromFile(students, numOfStudents);

    cout << "\nFreeing Memory" << endl;
    delete[] students;
    students = nullptr;

    return 0;
}