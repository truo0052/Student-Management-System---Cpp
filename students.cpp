#include "students.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Constructor implementation
Students::Students() : id(0), total(0), average(0.0) {
    for (int i = 0; i < 3; i++) {
        marks[i] = 0;
    }
}

void studentsData(Students* students, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        cout << "--- Student #" << (count += 1) << " ---" << endl;
        cout << "Enter ID: " << endl;
        cin >> students[i].id;
        cout << "Enter Name: " << endl;
        cin.ignore();
        getline(cin, students[i].name);
        
        students[i].total = 0; // Reset total
        for (int j = 0; j < 3; j++) {
            cout << "Enter Mark " << (j + 1) << ": " << endl;
            cin >> students[i].marks[j];
            students[i].total += students[i].marks[j];
        }
        
        students[i].average = students[i].total / 3.0;
        students[i].result = (students[i].average >= 50) ? "PASSING" : "FAILING";
    }
}

void studentsInfo(Students* students, int n) {
    cout << "--- Student Information ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Student #" << (i + 1) << ": " << endl;
        cout << "ID: " << students[i].id << ", Name: " << students[i].name << "\nMarks: ";
        
        for (int j = 0; j < 3; j++) {
            cout << students[i].marks[j];
            if (j < 2) cout << " ";
        }
        
        cout << "\nAverage: " << fixed << setprecision(2) << students[i].average
             << "\nTotal: " << students[i].total
             << "\nStatus: " << students[i].result << "\n" << endl;
    }
}

void highScoreStudents(Students* students, int n) {
    double maxScore = 0;
    int maxIndex = 0;
    
    cout << "--- Highest Scorer ---" << endl;
    for (int i = 0; i < n; i++) {
        if (students[i].average > maxScore) {
            maxScore = students[i].average;
            maxIndex = i;
        }
    }
    
    cout << "ID :" << students[maxIndex].id
         << ", Name: " << students[maxIndex].name
         << "\nMarks: " << flush;

    for (int j = 0; j < 3; j++) {
        cout << students[maxIndex].marks[j] << " " << flush;
    }

    cout << "\nTotal: " << students[maxIndex].total
         << ", Average: " << students[maxIndex].average
         << "\nStatus: " << students[maxIndex].result << "\n" << endl;
}
void saveToFile(Students* students, int n) {
    ofstream studentsFile;
    studentsFile.open("C:/Users/insta/Downloads/students.txt", ios::in | ios::trunc); // Open for input only and remove old contents
    for (int i = 0; i < n; i++) {
        studentsFile << "ID: " << students[i].id << ", Name: " << students[i].name<< "\nMark: " << flush;
        for (int j = 0; j <= n; j++) {
            studentsFile << fixed << setprecision(2) << students[i].marks[j] << " " << flush;
        }
        studentsFile << students[i].marks[i] << flush << "\nAverage: " << students[i].average << "\nTotal: " << students[i].total << "\nPassing: " << students[i].result << "\n"<< endl;
    }
    studentsFile.close();
    cout << "Saved File Successfully!\n" << endl;
}

void readFromFile(Students* students, int n) {
    string line;
    cout << "Opening File... students.txt" << endl;
    ifstream file ("C:/Users/insta/Downloads/students.txt", ios::out);
    if (file.is_open()) {
        while (getline (file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}