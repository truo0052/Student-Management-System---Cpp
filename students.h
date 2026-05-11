//
// Created by insta on 2026-01-21.
//

#ifndef ASSIGNMENT1_STUDENTS_H
#define ASSIGNMENT1_STUDENTS_H

#ifndef STUDENTS_H
#define STUDENTS_H

#include <string>
using namespace std;

struct Students {
    int id;
    int total;
    int marks[3]{};
    string name;
    string result;
    double average;

    // Constructor
    Students();
};

// Function declarations
void studentsData(Students* students, int n);
void studentsInfo(Students* students, int n);
void highScoreStudents(Students* students, int n);
void saveToFile(Students* students, int n);
void readFromFile(Students* students, int n);
#endif
#endif //ASSIGNMENT1_STUDENTS_H