#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Function to convert letter grade to grade points
double gradePoints(char grade) {
    switch (grade) {
        case 'A': return 10.0;
        case 'B': return 9.0;
        case 'C': return 8.0;
        case 'D': return 7.0;
        case 'E': return 6.0;
        case 'F': return 0.0;
        default: return -1.0; // Invalid grade
    
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<string> courseNames(numCourses);
    vector<char> grades(numCourses);
    vector<int> creditHours(numCourses);

    // Input course information
    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter the name of course " << i + 1 << ": ";
        cin.ignore(); // Ignore newline character in the buffer
        getline(cin, courseNames[i]);

        cout << "Enter the grade for course " << i + 1 << " (A, B, C, D, F): ";
        cin >> grades[i];

        cout << "Enter the credit hours for course " << i + 1 << ": ";
        cin >> creditHours[i];
    }

    // Calculate CGPA
    double totalGradePoints = 0.0;
    int totalCreditHours = 0;

    for (int i = 0; i < numCourses; ++i) {
        double points = gradePoints(grades[i]);
        if (points == -1.0) {
            cout << "Invalid grade entered. Exiting program." << endl;
            return 1;
        }
        totalGradePoints += points * creditHours[i];
        totalCreditHours += creditHours[i];
    }

    if (totalCreditHours > 0) {
        double cgpa = totalGradePoints / totalCreditHours;
        cout << fixed << setprecision(2);
        cout << "Your CGPA is: " << cgpa << endl;
    } else {
        cout << "No valid credit hours entered. Exiting program." << endl;
    }

    return 0;
}