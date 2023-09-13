/*
 *  Created on: August -2023
 *  Author: kruti Patel(40259909) and Bertin Mihigo Sano(40157663)
 *  Project: COEN243 end of class project
 *  specs:
*/


#include "Employee.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<Student> students;// an array of all students
std::vector<Staff> staffs;    //an array of all staff members



Student::Student(std::string firstname, std::string lastname,int ID, std::string DOB, float GPA, int startyear, float completedcredits, char program, bool isLoaded){
        this->_fName = firstname;
        this->_lName = lastname;
        this->_studentID = ID;
        this->_DOB= DOB;
        this->_GPA = GPA;
        this->_startyear=startyear;
        this->_completedCredits=completedcredits;
        this->_program=program;
        if(!isLoaded){
            students.push_back(*this);
        }

}
//All getters
std::string Student::_getFirstName(){
        return this->_fName;
}
std::string Student::_getLastName(){
        return this->_lName;
}
int Student::_getStudentID(){
        return this->_studentID;
}
std::string Student::_getDOB(){
        return this->_DOB;
}
float Student::_getGPA(){
        return this->_GPA;
}
int Student::_getStartYear(){
        return this->_startyear;
}
float Student::_getCompletedCredits(){
        return this->_completedCredits;
}
char Student::_getProgram(){
        return this->_program;
}
// All setters
void Student::_setFirstName(std::string newFirstName){
    this->_fName = newFirstName;
}
void Student::_setLastName(std::string newLastName){
    this->_lName = newLastName;
}
void Student::_setStudentID(int newID){
    this->_studentID = newID;
}
void Student::_setGPA(float newGPA){
    this->_GPA = newGPA;
}
// void Student::_setStartYear(int); not logical to change start year
void Student::_setCompletedCredits(float newCredits){
    this->_completedCredits = newCredits;
}
void Student::_setProgram(char newProgram){
    this->_program = newProgram;
}
// custom methods
bool Student::CompleteProgram(){
// This function returns true if the student has finished all the courses by comparing the completed credits with the required credit for the program that the student is enrolled in.
    if(this->_completedCredits >=140 && this->_program =='B')
        return true;
    else if(this->_completedCredits >=16 && this->_program =='M')
        return true;
    else if(this->_completedCredits >=12 && this->_program =='P')
        return true;
    else{
        // students has not completed yet!
        return false;
    }
}
std::string Student::StudentStatus(){
    if(this->_GPA >=3.5)
        return "A+";
    else if(this->_GPA >=3 && this->_GPA <3.5 )
        return "A";
    else if(this->_GPA >=2.5 && this->_GPA <3)
        return "B";
    else if(this->_GPA >=2 && this->_GPA <2.5)
        return "C";
    else if(this->_GPA <2)
        return "D";
    else{
        // this condition will NOT be reached
        return "DNE";
    }

}

void Student::PrintStudentInfo(){
    std::cout <<"\nFull name: "<< _fName <<" "<<_lName<< std::endl;
    std::cout <<"Student ID: "<<_studentID << std::endl;
    if(_program=='B')
        std::cout << "Program: Bachelors" << std::endl;
    else if(_program == 'M')
        std::cout << "Program: Masters" << std::endl;
    else if(_program=='P')
        std::cout << "Program: PhD" << std::endl;
    std::cout <<"Date of birth "<< _DOB <<std::endl;
    std::cout << "\nStudent Record:"<<std::endl;
    std::cout << "GPA: "<<_GPA << std::endl;
    std::cout << "Start year: "<<_startyear << std::endl;
    std::cout << "Completed Credits: "<<_completedCredits << std::endl;
}
Student::~Student(){

}
// END OF STUDENT DECLARATION





Staff::Staff(std::string FName, std::string LName, int empID, int hiringDate, char bonusCode, double salary,bool isLoaded){
    this->__firstName = FName;
    this->__lastName = LName;
    this->__ID = empID;
    this->__hireDate = hiringDate;
    this->__bonusCode = bonusCode;
    this->__currentSalary = salary;
    if(!isLoaded){
        staffs.push_back(*this);
    }
}

std::string Staff::__getFirstName(){
        return __firstName;
}
std::string Staff::__getLastName(){
        return __lastName;
}

int Staff::__getID() {
        return __ID;
}

int Staff::__getHireDate(){
        return __hireDate;
}
char Staff::__getBonusCode(){
        return __bonusCode;
}
double Staff::__getCurrentSalary(){
        return __currentSalary;
}


void Staff::__setFirstName(std::string firstName){
        this->__firstName = firstName;
}
void Staff::__setLastname(std::string lastName){
        this->__lastName = lastName;
}
void Staff::__setID(int newID){
        this->__ID  = newID;
}
void Staff::__setHireDate(int Hiredate){
        this->__hireDate = Hiredate;
}
void Staff::__setBonusCode(char newBonusCode){
        this->__bonusCode = newBonusCode;
}
void Staff::__setCurrentSalary(double newSalary){
        this->__currentSalary = newSalary;
}

void Staff::__Print_Staff_Info(){ // This function prints out all the information of one staff (all the attributes).
        std::cout << std::endl;
        std::cout <<"First name: "<<__firstName<< std::endl;
        std::cout<<"Last name: "<<__lastName<< std::endl;
        std::cout<<"Employee ID: " << __ID<< std::endl;
        std::cout<<"Hired on: "<<__hireDate<< std::endl;
        std::cout<< "Current salary: " << __currentSalary<< std::endl;
        std::cout <<"Salary bonus code: "<< __bonusCode<< std::endl;
        std::cout <<"Estimated Salary Increase according to bonus code: "<< this->__Calculate_Salary()<< std::endl;
        std::cout << std::endl;
}
double Staff::__Calculate_Salary() {// see function specs in the PDF
        const char bonus {this->__bonusCode};
        const double currentSalary {this->__currentSalary};
        double newSalary {};
        switch(bonus){
            case 'A':
                newSalary = currentSalary + (currentSalary*8.00/100);
                break;
            case 'B':
                newSalary = currentSalary + (currentSalary*6.00/100);
                break;
            case 'C':
                newSalary = currentSalary + (currentSalary*3.00/100);
                break;
            case 'D':
                newSalary = currentSalary + (currentSalary*1.00/100);
                break;
            case 'E':
                newSalary = currentSalary + (currentSalary*0.00/100);
                break;
            default:
                newSalary = currentSalary;
                break;
        }
        return newSalary;
}
Staff::~Staff()  {
        // destructor will delete pointer to object and save object data to disk
}






Student_Staff::Student_Staff(const std::string filename) { // full path of filename required!
    if((filename.find("staff.txt")) != std::string::npos){
        // read staff.txt
        std::string line; // get a line
        std::string subline; // extract within that line given delimiter |
        std::fstream file {filename, std::ios_base::in};
        if(file.is_open()) { // execute this section if read file was successful
            while (!file.eof()) {
                getline(file, line, '\n');// get a line and store into file.
                std::stringstream iss{line}; // string stream to capture a line
                int count{0}; // count columns of my data start from 0 to 5
                while (getline(iss, subline, '|')) {
                    if (count == 0)
                        staffstructure.firstname = subline;
                    else if (count == 1)
                        staffstructure.lastname = subline;
                    else if (count == 2)
                        staffstructure.id = stoi(subline);
                    else if (count == 3)
                        staffstructure.hiredate = stoi(subline); // convert string to integer
                    else if (count == 4)
                        staffstructure.bonuscode = subline[0]; //
                    else if (count == 5)
                        staffstructure.salary = stod(subline); // convert string to double
                    else
                        break; // this condition will never reach here unless file is unstructured

                    count++; // jump to next column
                }
                Staff *new_staff = new Staff(staffstructure.firstname, staffstructure.lastname,
                                             staffstructure.id, staffstructure.hiredate, staffstructure.bonuscode, staffstructure.salary, true);
                staffs.push_back(*new_staff); // add new object to the staffs dynamic array
                std::clog <<staffs.size()<<" staff employees loaded from disk"<< std::endl;

            } // finish reading all lines here
            this->path = filename;
        }
        else{
            std::cerr << "Error! Cannot read from file likely due to the formatting issue\n";
            exit(EXIT_FAILURE);
        }
        file.close();
        //Below segment is to assign memory addresses to pointers!
        p_Staffs = staffs.data();

    } // reading from staff.txt ends here
    else if((filename.find("student.txt")) != std::string::npos){
        //read student.txt
        std::string line; // get a line
        std::string subline; // extract within that line given delimiter |
        std::fstream file {filename, std::ios_base::in};
        if(file.is_open()) { // execute this section if read file was successful
            while (!file.eof()) {
                getline(file, line, '\n');// get a line and store into file.
                std::stringstream iss{line}; // string stream to capture a line
                int count{0}; // count columns of my data start from 0 to 5
                while (getline(iss, subline, '|')) {
                    if (count == 0)
                        studentstructure.firstname = subline;
                    else if (count == 1)
                        studentstructure.lastname = subline;
                    else if (count == 2)
                        studentstructure.studentID = stoi(subline); // convert string to integer
                    else if (count == 3)
                        studentstructure.DOB = subline;
                    else if (count == 4)
                        studentstructure.GPA = stof(subline); //
                    else if (count == 5)
                        studentstructure.startyear = stoi(subline); // convert string to int
                    else if(count ==6 )
                        studentstructure.completedCredits = stof(subline);
                    else if(count==7)
                        studentstructure.program = subline[0];
                    else
                        break; // this condition will never reach here unless file is unstructured

                    count++; // jump to next column
                }
                Student *new_student = new Student(studentstructure.firstname, studentstructure.lastname, studentstructure.studentID,
                                                   studentstructure.DOB, studentstructure.GPA, studentstructure.startyear, studentstructure.completedCredits,
                                                   studentstructure.program, true);
                students.push_back(*new_student); // add new object to the students dynamic array
                std::clog <<students.size()<<" students loaded from disk"<< std::endl;

            } // finish reading all lines here
            this->path = filename;
        }
        else{
            std::cerr << "Error! Cannot read from file likely due to the formatting issue\n";
            exit(EXIT_FAILURE);
        }
        file.close();
        //Below segment is to assign memory addresses to pointers!
        p_Students = students.data();
    }
    else {
        std::cerr << filename <<" is an invalid file or directory" << std::endl;
        exit(1);
    }

}// end of constructor

void Student_Staff::Highest_GPA() {
    int V = students.size();
    float arrGPA[V], sorted_arrGPA[V];
    for (size_t i= 0; i < V-1; i++) { // build an array of all GPAs
        arrGPA[i] = students.at(i)._getGPA();
    }
    std::sort(arrGPA, arrGPA+V);
    //highest gpa is the last element
    float foundHighestGPA = arrGPA[V-1];
    for (size_t i= 0; i < V-1; i++) { // a loop to find a student with highest gpa and print him
        if (foundHighestGPA == students.at(i)._getGPA()){
            std::cout << "\n Student with the highest GPA:\n";
            students.at(i).PrintStudentInfo();
            break; // break the loop here
        }
        else
            continue;
    }
}

// This function accept an array of students, and size and returns the total number of undergraduate students
int Student_Staff::N_of_UnderGrad() {
    int count {0}; // count the number of undergrad students
    int V = students.size();
    for (size_t i= 0; i < V-1; i++) { // a loop to count number of undergrads
        if (students.at(i)._getProgram() =='B'){ //'B' means bachelors
            count++;
        }
        else
            continue;
    }
    return count;
}


//This function accepts an array of staff, and size and a hiring year and prints out the name of all staff who have been hired in that year.
void Student_Staff::Same_Hire_Year(const int year){
    int staffSIZE = staffs.size();
    std::cout << "\nBelow is a list of staff members who were hired on: "<<year<< std::endl;
    for(size_t i=0;i<staffSIZE-1;i++){ // Traverse the staffs container look for staffs hired on =year
        if(staffs.at(i).__getHireDate() == year){
            std::cout << staffs.at(i).__getFirstName() <<" "<< staffs.at(i).__getLastName() << std::endl;
        }
        else
            continue;
    }
    std::cout << "\n\t\tThe list ends here\t\t\n";
}

// This method will be used to save all employee info on the disk!
Student_Staff::~Student_Staff(){
    std::string currentPath = std::filesystem::current_path();
    std::string savePath = (this->path);
    //std::clog << "Save Path: "<< () << std::endl;
    int sizeof_staffs =staffs.size();
    int sizeof_students= students.size();
    std::fstream staffO;
    std::fstream studentO; // create 2 streams of staffs and students.
    //write to staff.txt
    if((savePath.find("staff.txt")) != std::string::npos){
        staffO.open(savePath, std::ios_base::out);
        if(staffO){
            // start to write here
            for(long int i=0; i<sizeof_staffs-1;i++){
                // first name | last name | id | hire date | bonus code | salary
                staffO << staffs[i].__getFirstName() <<"|"<<staffs[i].__getLastName()<<"|"<<staffs[i].__getID()<<"|"<< staffs[i].__getHireDate()<<"|"<<staffs[i].__getBonusCode()<<"|"<<staffs[i].__getCurrentSalary() <<std::endl;
            }
            //end of writing to file
            staffO.close();
            std::clog << "Contents were saved to: "<<savePath<<"\n";
        }
    }
    //write to students.txt
    if(savePath.find("student.txt") != std::string::npos){
        studentO.open(savePath, std::ios_base::out);
        if(studentO){
            // start to write here
            for(size_t i=0; i<sizeof_students-1;i++){
                //first name|lastname|student id|date of birth|GPA|start year|completed credts|program
                studentO<<students[i]._getFirstName() <<"|"<< students[i]._getLastName() <<"|"<< students[i]._getStudentID() <<"|"<< students[i]._getDOB()<<"|"<< students[i]._getGPA() <<"|"<< students[i]._getStartYear() <<"|"<< students[i]._getCompletedCredits() <<"|"<< students[i]._getProgram()<<std::endl;
            }
            //end of writing to file
            studentO.close();
            std::clog << "Contents were saved to: "<<savePath<<"\n";
        }
    }

}

std::vector<Student>  Student_Staff::getStudents(){
        return students;

}
std::vector<Staff> Student_Staff::getStaffs(){
        return staffs;
}










