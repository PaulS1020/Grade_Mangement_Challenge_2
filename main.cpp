#include <iostream>
#include <limits>
using namespace std;

/*
    Name: Paul Soy
    Date: September 8, 2025
    Purpose: Create grading program
    Assignment: Challenge 2 - Grade Mangement with Reference Parameters
*/

// This is a list of functions that we make to tell the program what functions exist.
// So we have one that input grades and uses reference parameters which is indicated by the & sign.
/* The calculate average one uses the const values of parameters
   and the get letter grade parameter uses one const value parameter which is the average.
*/
void inputGrades(double& g1, double& g2, double& g3);
double calculateAverage(const double g1, const double g2, const double g3);
char getLetterGrade(const double average);

// We have our main function with the three grade variables all listed.
int main() {
    double g1 = 0;
    double g2 = 0;
    double g3 = 0;
    int choice = 0; // The int Choice variable is for the menu choice.

    // This is a do while loop we'll repeat until the user chooses to end.
    do {
        cout << "1.Input Grades" << endl;
        cout << "2.Calculate and Display Average" << endl;
        cout << "3.Assign and Display Letter Grade" << endl;
        cout << "4.Quit" << endl;
        cout << "Enter choice: ";

        /* This will try to read a number into the choice input. It also blocks something that is not a number
           like a letter. It blocks a letter so that the code will not run infinitely. */
        if (!(cin >> choice)) {
            cin.clear(); // This is used to clear the error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue; // Restart to menu
        }
         // The switch statement allows users to choose what they want to do based on the choices given.
        switch (choice) {
            case 1:
                // Calls input grades and their passed as a reference parameter.
                inputGrades(g1, g2, g3);
                break;
            case 2:
                // Calls calculate average to find the mean of the three grades
                cout << "Average is " << calculateAverage(g1, g2, g3) << endl;
                break;
            case 3:
                // The letter grade will will use the mean grades and pass that to a letter grade.
                cout << "Letter grade is " << getLetterGrade(calculateAverage(g1, g2, g3)) << endl;
                break;
            case 4:
                // End loop
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4); // Closes at loop 4

    return 0;
}

/* This is a void function called input grades.
It asks the user for three grades and stores them in g1, g2, and g3
by using reference parameters. It also makes sure each grade is between 0 and 100. */
void inputGrades(double& g1, double& g2, double& g3) {
    cout << "Enter first grade (0 to 100): ";
    cin >> g1;
    while (g1 < 0 || g1 > 100) {
        cout << "Invalid input. Please enter grade between 0 and 100." << endl;
        cin >> g1;
    }

    cout << "Enter second grade (0 to 100): ";
    cin >> g2;
    while (g2 < 0 || g2 > 100) {
        cout << "Invalid input. Please enter grade between 0 and 100." << endl;
        cin >> g2;
    }

    cout << "Enter third grade (0 to 100): ";
    cin >> g3;
    while (g3 < 0 || g3 > 100) {
        cout << "Invalid input. Please enter grade between 0 and 100." << endl;
        cin >> g3;
    }
}

// Calculate the mean.
double calculateAverage(const double g1, const double g2, const double g3) {
    return (g1 + g2 + g3) / 3.0;
}

// Gets the letter grade based on the average value and returns it.
char getLetterGrade(const double average) {
    if (average >= 90) {
        return 'A';
    }
    else if (average >= 80) {
        return 'B';
    }
    else if (average >= 70) {
        return 'C';
    }
    else if (average >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}

