#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Course {
    double grade;
    int credits;
    string name;
    
};

double calculateGPA(const vector<Course>& courses) {
    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (const auto& course : courses) {
        totalGradePoints += course.grade * course.credits;
        totalCredits += course.credits;
    }

    return (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;
}

int main() {
    vector<Course> courses;
    int numCourses;
    cout << "Enter the no.of courses: ";
    cin >> numCourses;
    int i = 0;
    while(i < numCourses)
    {
        Course course;
        cout << "Enter the name of course " << (i + 1) << ": ";
        cin >> course.name;
        cout << "Enter the number of credits for " << course.name << ": ";
        cin >> course.credits;
        cout << "Enter the grade for " << course.name << ": ";
        cin >> course.grade;
        courses.push_back(course);
        i++;
    }

    cout << "\nIndividual Course Grades:\n";
    for (const auto& course : courses) 
        cout << course.name << ": " << course.grade << " (" << course.credits << " credits)" << endl;
    

    double gpa = calculateGPA(courses);
    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << accumulate(courses.begin(), courses.end(), 0, [](int sum, const Course& c) { return sum + c.credits; }) << endl;
    cout << "Total Grade Points: " << accumulate(courses.begin(), courses.end(), 0.0, [](double sum, const Course& c) { return sum + (c.grade * c.credits); }) << endl;
    cout << "GPA for the semester: " << gpa << endl;

    cout << "His/Her CGPA is: " << gpa << endl;
    system("pause");
    return 0;
}
