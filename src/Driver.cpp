/*
*  Created on: August -2023
*  Author: kruti Patel(40259909) and Bertin Mihigo Sano(40157663)
*  Project: COEN243 end of class project
*  specs:
*/
#include "Employee.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <memory>

//extern std::vector<Student> students;// an array of all students
//extern std::vector<Staff> staffs;    //an array of all staff members

#define MAX numeric_limits<streamsize>::max()
using namespace std;
void createStudent();

int main(){
    cout << setw(10) << "\n\n******Welcome to the University Records System******\n\n" << setw(10);
    string studentFilePath {};
    string staffFilePath{};
    cout <<"Please enter the full path of the location of staff database aka staff.txt:\n";
    cin >> staffFilePath;
    cout <<"Please enter the full path of the location of student database aka student.txt:\n";
    cin >> studentFilePath;
    //Student_Staff *GETSTAFF = new Student_Staff(staffFilePath);
    //Student_Staff *GETSTUDENT = new Student_Staff(studentFilePath);
    unique_ptr<Student_Staff> GETSTAFF = make_unique<Student_Staff>(staffFilePath);
    unique_ptr<Student_Staff> GETSTUDENT = make_unique<Student_Staff>(studentFilePath);

    int students_size =GETSTUDENT->getStudents().size();
    int staffs_size = GETSTAFF->getStaffs().size();
    //print all members of staff
    for(int y=0;y<staffs_size-1;y++){
        GETSTAFF->getStaffs().at(y).__Print_Staff_Info();
    }

    // print all students
    for(int y=0;y<students_size-1;y++){
        GETSTUDENT->getStudents().at(y).PrintStudentInfo();
    }

    // the print below print total number of undergrads
    cout << "\nTotal number of students enrolled in Bachelors:"<<GETSTUDENT->N_of_UnderGrad()<< endl;

    // print info of a student with highest gpa
    GETSTUDENT->Highest_GPA();
    cout <<"\nEnter a year between 2000-2024 to check employees who were hired that year:\n";
    int year;
    while(cin>>year){
        if(year>=2000 && year<=2024){
            GETSTAFF->Same_Hire_Year(year);
            break;
        }
        else{
            cerr<<"Error:enter a valid year!\n";
            continue;
        }
    }
    cout <<"Would you like to add a new student to the database(Y or N)?" << endl;
    char response;
    cin >> response;
    if (response == 'Y' || response == 'y')
        createStudent();
    // continue program here




    //free memory before end of program
    return 0;



}

std::string firstname; //0
std::string lastname; //1
int studentID; //2
std::string DOB; //3
float GPA; //4
int startyear; //5
float completedCredits; //6
char program; //7
// functions definitions

void createStudent(){
    st_d read;
    cout << "Enter student\'s first name: ";
    cin >> read.firstname;
    cout << "Enter student\'s last name: ";
    cin >> read.lastname;

    cout <<"Enter student\'s new ID (integer): ";
    while(!(cin >> read.studentID)) {
        cerr << "\nplease type a valid input\n";
        cin.clear();
        cin.ignore(MAX, '\n');
    }
    cout <<"Enter student\'s Date of birth (YYYY/MM/DD): ";
    while(!(cin >> read.DOB)) {
        cerr << "\nplease type a valid input\n";
        cin.clear();
        cin.ignore(MAX, '\n');
    }
    cout <<"Enter student\'s GPA(0.0-4.3): ";
    while(!(cin >> read.GPA)) {
        cerr << "\nplease type a valid input\n";
        cin.clear();
        cin.ignore(MAX, '\n');
    }
    cout <<"Enter student\'s start year: ";
    while(!(cin >> read.startyear)) {
        cerr << "\nplease type a valid input\n";
        cin.clear();
        cin.ignore(MAX, '\n');
    }
    cout << "Enter student\'s completed credits: ";
    while(!(cin  >> read.completedCredits)) {
        cerr << "\nplease type a valid input\n";
        cin.clear();
        cin.ignore(MAX, '\n');
    }
    cout << "Enter student\'s program(B: Bachelors, M:Masters, P:PhD): ";
    while(!(cin >> read.program)) {
        cerr << "\nplease type a valid input\n";
        cin.clear();
        cin.ignore(MAX, '\n');
    }
Student new_student(read.firstname, read.lastname, read.studentID, read.DOB, read.GPA, read.startyear, read.completedCredits, read.program, false );
} // end of createStudent()