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

void calcAverages(Student* sArray, int studentCount, int testCount);

void getLetterGrades(Student* sArray, int studentCount);

int main()
{
    int studentTotal;
    int testTotal;

    Student* students = getData("student_data.txt", studentTotal, testTotal);

    calcAverages(students, studentTotal, testTotal);

    getLetterGrades(students, studentTotal);

    return 0;
}

/*
    Summary: Gets data from a specified file, taking the number of students and tests from its header before reading the names, IDs, and test scores of each student.
    Parameters: fileName, the string for the file's exact name, students, a reference to an integer keeping the total number of students, and tests, a reference to the total number of tests.
    Return: A dynamic array of Student structs, of however many students there are.
    Preconditions: fileName must not only refer to a text file that exists, but one that is formatted perfectly. Uses sstream.
    Postconditions: Reads and parses through a text file. Allocates memory to the dynamic Student array and its inner dynamic test scores array. This memory must be freed later.
*/
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

    dataFile.close(); // closes file
    return studentArray;
}

/*
    Summary: Goes through the struct array for students, calculating and updating their average score by averaging out the test scores of each student.
    Parameters: sArray, the array of students, int studentCount, the number of total students, and testCount, the number of total tests.
    Return: None.
    Preconditions: sArray must be filled with valid data, studentCount and testCount should have values assigned already.
    Postconditions: The average of each student will be changed as a result of calling this function.
*/
void calcAverages(Student* sArray, int studentCount, int testCount)
{
    for (int i = 0; i < studentCount; i++)
    {
        int total = 0;

        for (int j = 0; j < testCount; j++)
        {
            total += sArray[i].testScores[j];
        }

        double average = float(total) / float(testCount); // Takes average

        sArray[i].averageScore = average; // Stores average in struct
    }
}

/*
    Summary: Gets the letter grades for every student in the Student array, according to their averages.
    Parameters: sArray, the array of students with all their info, studentCount, the total number of all students.
    Return: None.
    Preconditions: Every student in sArray must have a real average grade already added. studentCount must be collected prior to calling.
    Postconditions: Every student in sArray will have their letterGrade updated to a letter corresponding to their average range.
*/
void getLetterGrades(Student* sArray, int studentCount)
{
    for (int i = 0; i < studentCount; i++)
    {
        double average = sArray[i].averageScore;

        if (average >= 90)
        {
            sArray[i].letterGrade = 'A';
        }
        else if (average >= 80)
        {
            sArray[i].letterGrade = 'B';
        }
        else if (average >= 70)
        {
            sArray[i].letterGrade = 'C';
        }
        else if (average >= 60)
        {
            sArray[i].letterGrade = 'D';
        }
        else
        {
            sArray[i].letterGrade = 'F';
        }
    }
}

