#include <iostream>
#include <fstream>

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

    Student* students;

    return 0;
}


