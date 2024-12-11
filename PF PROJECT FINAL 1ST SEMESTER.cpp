#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Structure to hold student information
struct Student {
int id;
string name;
string email;
};
//Structure to hold course information
struct Course {
int id;
string name;
int availableSeats;
};
//Class for the Enrollment System
class EnrollmentSystem {
private:
vector<Student> students;
vector<Course> courses;
int generateStudentID() {
return students.size() + 1; // Simple incremental ID
}
int generateCourseID() {
return courses.size() + 1; //Simple incremental ID
}
public:
//Function to register a new student
void registerStudent() {
Student newStudent;
newStudent.id = generateStudentID();
cout<<"Enter student name: ";
cin.ignore(); // To clear the buffer
getline(cin, newStudent.name);
cout<<"Enter student email: ";
cin>>newStudent.email;
students.push_back(newStudent);
cout<<"Student registered successfully! ID: " << newStudent.id << endl;
}
//Function to add a course (for admin functionality)
void addCourse() {
Course newCourse;
newCourse.id = generateCourseID();
cout<<"Enter course name: ";
cin.ignore(); // To clear the buffer
getline(cin, newCourse.name);
cout<<"Enter available seats: ";
cin>>newCourse.availableSeats;
courses.push_back(newCourse);
cout<<"Course added successfully! ID: " << newCourse.id << endl;
}
//Function to enroll a student in a course
void enrollStudent() {
int studentID, courseID;
cout<<"Enter student ID: ";
cin>>studentID;
cout<<"Enter course ID: ";
cin>>courseID;
//Check if student and course exist
if (studentID <= 0 || studentID > students.size() || 
courseID <=0 || courseID > courses.size()) {
cout<<"Invalid student or course ID." << endl;
return;
}
Course &selectedCourse = courses[courseID - 1];
if (selectedCourse.availableSeats > 0) {
selectedCourse.availableSeats--;
cout<<"Student"<<students[studentID - 1].name 
<<"successfully enrolled in"<<selectedCourse.name<<"!"<<endl;
} else {
cout<<"No seats available in"<<selectedCourse.name<<"."<<endl;
}
}
//Display all students
void displayStudents() {
if (students.empty()) {
cout<<"No students registered yet." << endl;
return;
}
cout<<"Registered Students:"<<endl;
for (const auto &student :students) {
cout<<"ID:"<<student.id<<",Name:"<<student.name 
<<",Email:"<<student.email<< endl;
}
}
//Display all courses
void displayCourses() {
if (courses.empty()) {
cout<<"No courses available yet."<< endl;
return;
}
cout<<"Available Courses:" << endl;
for (const auto &course : courses) {
cout<<"ID:"<<course.id<<",Name:"<<course.name 
<<",Seats:"<<course.availableSeats << endl;
}
}
};
int main() {
EnrollmentSystem system;
int choice;
while (true) {
cout<<"\n--- Student Enrollment System ---\n";
cout<<"1.Register Student\n";
cout<<"2.Add Course\n";
cout<<"3.Enroll Student in a Course\n";
cout<<"4.Display Students\n";
cout<<"5.Display Courses\n";
cout<<"6.Exit\n";
cout<<"Enter your choice:";
cin>>choice;
switch (choice) {
case 1:
system.registerStudent();
break;
case 2:
system.addCourse();
break;
case 3:
system.enrollStudent();
break;
case 4:
system.displayStudents();
break;
case 5:
system.displayCourses();
break;
case 6:
cout<<"Exiting system.Goodbye!"<<endl;
return 0;
default:
cout<<"Invalid choice.Try again!"<<endl;
}
}
}
