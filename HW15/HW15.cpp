#include <iostream>
#include <algorithm>
#include <iomanip>

const int Size = 4;

struct Student
{
    std::string name;
    double marks[4];
};

// Task 1: Calculate the average marks of a student
double AVGmarks(const Student& st)
{
    double sum = 0;
    for (int i = 0; i < Size; i++)
    {
        sum += st.marks[i];
    }
    return sum / Size;
}

// Task 3: Find the student with the highest average marks
Student* findBestStudent(Student* st, int count)
{
    if (count == 0)
        return nullptr;
    Student* bestStudent = &st[0];
    double bestAVG = AVGmarks(*bestStudent);
    for (size_t i = 1; i < count; i++)
    {
        double curAVG = AVGmarks(st[i]);
        if (curAVG > bestAVG)
        {
            bestStudent = &st[i];
            bestAVG = curAVG;
        }
    }
    return bestStudent;
}

// Task 4: Count the number of students with an average above a given threshold
int countStudentsAboveAVG(Student* st, int count, double N)
{
    int res = 0;
    for (size_t i = 0; i < count; i++)
    {
        if (AVGmarks(st[i]) > N)
            res++;
    }
    return res;
}

// Task 6: Sort students by their average marks in descending order
bool compareByAverage(const Student& a, const Student& b) 
{
    return AVGmarks(a) > AVGmarks(b);
}

void sortStudentsByAverage(Student* students, int count)
{
    std::sort(students, students + count, compareByAverage);
}

int main()
{
    Student students[] = {
        {"Alice", {85, 90, 78, 92}},
        {"Bob", {76, 88, 80, 85}},
        {"Charlie", {92, 95, 89, 91}},
        {"David", {70, 65, 75, 80}}
    };

    int count = sizeof(students) / sizeof(students[0]);

    std::cout << "Average marks for each student:\n";
    for (int i = 0; i < count; i++)
    {
        std::cout << students[i].name << ": " << std::fixed << std::setprecision(2) << AVGmarks(students[i]) << "\n";
    }

    Student* bestStudent = findBestStudent(students, count);
    if (bestStudent)
    {
        std::cout << "\nBest student: " << bestStudent->name << " with an average of " << std::fixed << std::setprecision(2) << AVGmarks(*bestStudent) << "\n";
    }

    double threshold = 85.0;
    int aboveThreshold = countStudentsAboveAVG(students, count, threshold);
    std::cout << "\nNumber of students with an average above " << threshold << ": " << aboveThreshold << "\n";

    sortStudentsByAverage(students, count);
    std::cout << "\nStudents sorted by average marks (descending order):\n";
    for (int i = 0; i < count; i++)
    {
        std::cout << students[i].name << ": " << std::fixed << std::setprecision(2) << AVGmarks(students[i]) << "\n";
    }

    return 0;
}