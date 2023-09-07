/*
*  Created on: August -2023
*  Author: kruti Patel(40259909) and Bertin Mihigo Sano(40157663)
*  Project: COEN243 end of class project
*  specs:
*/
#pragma once

#include <string>
#include <vector> // to be used for dynamic array


struct st_f { // this structure will help me to read from a structured staff file
    std::string firstname; //0
    std::string lastname; //1
    int id; //2
    int hiredate; //3
    char bonuscode; //4
    double salary; //5
} static staffstructure;

struct st_d { // this struct will help to read from student.txt file
    std::string firstname; //0
    std::string lastname; //1
    int studentID; //2
    std::string DOB; //3
    float GPA; //4
    int startyear; //5
    float completedCredits; //6
    char program; //7
} static studentstructure;


// a subclass of students
class Student {
private:
    std::string _fName;
    std::string _lName;
    int _studentID;
    std::string _DOB;
    float _GPA;
    int _startyear; //5
    float _completedCredits; //6
    char _program; //7
public:
    //Student(); // empty constructor
    Student(std::string, std::string, int, std::string, float, int, float, char, bool);

    //All getters
    std::string _getFirstName();

    std::string _getLastName();

    int _getStudentID();

    std::string _getDOB();

    float _getGPA();

    int _getStartYear();

    float _getCompletedCredits();

    char _getProgram();

    // All setters
    void _setFirstName(std::string);

    void _setLastName(std::string);

    void _setStudentID(int);

    void _setDOB(std::string);

    void _setGPA(float);

    void _setStartYear(int);

    void _setCompletedCredits(float);

    void _setProgram(char);

    // custom methods
    bool CompleteProgram();

    std::string StudentStatus();

    void PrintStudentInfo();

    ~Student();

};

// a subclass of Staff
class Staff {
private:
    std::string __firstName;
    std::string __lastName;
    int __ID;
    int __hireDate;
    char __bonusCode;
    double __currentSalary;

public:
    //constructor
    Staff(std::string, std::string, int, int, char, double, bool);

    ~Staff(); // destructor will delete pointer to object and save object data to disk
    // All Get functions
    std::string __getFirstName();

    std::string __getLastName();

    int __getID();

    int __getHireDate();

    char __getBonusCode();

    double __getCurrentSalary();

    // All Set functions
    void __setFirstName(std::string);

    void __setLastname(std::string);

    void __setID(int);

    void __setHireDate(int);

    void __setBonusCode(char);

    void __setCurrentSalary(double);

    //custom methods
    void __Print_Staff_Info();// This function prints out all the information of one staff (all the attributes).
    double __Calculate_Salary();   // see function specs in the PDF
};


static std::vector<Student> students;// an array of all students
static std::vector<Staff> staffs;    //an array of all staff members

// a subclass used to retrieve lists of students and staff saved to the system
class Student_Staff {
private:
    Student *p_Students{nullptr}; // points directly to the first member of students
    Staff *p_Staffs = {nullptr}; // points directly to the first member of staffs
    std::string path; // path where contents will be saved! should be the same as client input

public:
    //Reads student.txt files and creates a dynamic array of students
    //Reads staff.txt files and creates a dynamic array of staff
    // full path of filename required!
    Student_Staff(const std::string filename);

    void
    Highest_GPA();   // This function accepts an array of students and size. Then prints out the information of the one who has the highest GPA
    int
    N_of_UnderGrad(); // This function accept an array of students, and size and returns the total number of undergraduate students
    void Same_Hire_Year(
            const int);// This function accepts an array of staff, and size and a hiring year and prints out the name of all staff who have been hired in that year.
    std::vector<Student> getStudents();

    std::vector<Staff> getStaffs();

    // This method will be used to save all employee info on the disk!
    ~Student_Staff();
};



