#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// struct definition of Student
struct Student {
    string name;
    int id;
    int* testScores;
    double averageScore;
    char letterGrade;
};

// Function prototypes

Student* getData(string fileName, int& students, int& tests);

void calcAverages(Student* structArr, int studentCount, int testCount);

void getLetterGrades(Student* structArr, int studentCount);

int main()
{
    int studentTotal;
    int testTotal;

    Student* students = getData("student_data.txt", studentTotal, testTotal);

    return 0;
}

Student* getData(string fileName, int& students, int& tests)
{
    fstream dataFile(fileName);

    Student* studentArray;

    if (dataFile)
    {
        string line;

        // Gets line and stringstream from first line of text file
        getline(dataFile, line);
        stringstream ss(line);

        ss >> students >> tests; // Takes number of students and tests from the header

        studentArray = new Student[students];

        for (int i = 0; i < students; i++) // For all the students
        {
            getline(dataFile, line); // Gets a new line
            stringstream ss(line);

            ss >> studentArray[i].name >> studentArray[i].id;

            studentArray[i].testScores = new int[tests];

            for (int j = 0; j < tests; j++) // For all the test scores of i student
            {
                ss >> studentArray[i].testScores[j];
            }
        }
    }
    else
    {
        cout << "ERROR: File could not be opened.\n";
        exit(1);
    }

    return studentArray;
}


