#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
#ifndef ROSTER_H
#define ROSTER_H

using namespace std;


Roster::Roster()
{
    // initialization
    Student students[5];
    Student *classRosterArray[5];

    // array of student objects
    Student students[5] = {
        {"A1", "John", "Smith", "John1989@gm ail.com", 20, {30, 35, 40}, "SECURITY"},
        {"A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, {50, 30, 40}, "NETWORK"},
        {"A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, {20, 40, 33}, "SOFTWARE"},
        {"A4", "Erin", "Black", "Erin.black@comcast.net", 22, {50, 58, 40}, "SECURITY"},
        {"A5", "Ana", "Escobedo", "myemailaddress@gmail.com", 23, {20, 21, 22}, "SOFTWARE"}};

    // populate array w array of student objects
    for (int i = 0; i <= 5; i++)
    {
        classRosterArray[i] = &students[i];
    }

    // print vals w pointers
    for (int i = 0; i <= 5; i++)
    {
        cout << classRosterArray[i]->getId() << ", ";
        cout << classRosterArray[i]->getFName() << ", ";
        cout << classRosterArray[i]->getLName() << ", ";
        cout << classRosterArray[i]->getEmail() << ", ";
        cout << classRosterArray[i]->getDays()[0] << ", ";
        cout << classRosterArray[i]->getDays()[1] << ", ";
        cout << classRosterArray[i]->getDays()[2] << ", ";
        cout << classRosterArray[i]->getDegree() << endl;
    }
}

Roster::Roster(int numStudents) {
    this->numStudents = numStudents;
    this->lastIndex = 0;
    for (int i = 0; i <numStudents; i++) {
        this->classRosterArray[i] = new Student*[numStudents];
    }
    return;
}

string Roster::GetId(int index) {
    string studentId = classRosterArray[index]->getId();
    return studentId;
}

void Roster::parse(string studentData)
{ 
    string studentId, firstName, lastName, emailAddress;
    int yearsOld, daysCourse1, daysCourse2, daysCourse3;

    if (lastIndex < numStudents) {
        lastIndex++;

        //set the id
        int rhs = studentData[lastIndex].find(", ");
        classRosterArray[lastIndex]->setId(studentData[lastIndex].substr(0, rhs));

        //fname
        int lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setFName(studentData[lastIndex].substr(lhs, rhs - lhs));

        //lname
        int lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setLName(studentData[lastIndex].substr(lhs, rhs - lhs));

        //email
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setEmail(studentData[lastIndex].substr(lhs, rhs - lhs));

        //age
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setAge(studentData[lastIndex].substr(lhs, rhs - lhs));

        //days in each course
        //day 1
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        daysCourse[0] = stoi(studentData[lastIndex].subtr(lhs, rhs - lhs));

        //day 2
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        daysCourse[1] = stoi(studentData[lastIndex].subtr(lhs, rhs - lhs));

        //day3
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        daysCourse[2] = stoi(studentData[lastIndex].subtr(lhs, rhs - lhs));

        classRosterArray[lastIndex]->setDays(daysCourse);

        //degree
        lhs = rhs + 1;
        rhs = studentData.find(",", degreeProgram);
        string type = studentData.substr(lhs, rhs - lhs);
        if (type == "Software") {
            classRosterArray[lastIndex]->setDegree(Software);
        }
        else if (type == "Security") {
            classRosterArray[lastIndex]->setDegree(Security);
        }
        else if (type == "Network"){
            classRosterArray[lastIndex]->setDegree(Network);
        }
        else {
            cout << "Degree does not exist" << endl;
        }
        lastIndex++;
    }
}


//little remove ststament
bool Roster::remove(string studentId){
    bool found = false;
    for (int i = 0; i<= ind; i++){
        if (this->classRosterArray[i]->getId() == studentId){
            found = true;
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[ind];
            ind--;//roster down one element
        }
    }
    return found;
}

void Roster::printAll() {
//parse student array and call print method for each one
for (int i = 0; i<=ind; i++)
(this->classRosterArray)[i]->print();
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int yearsOld, int daysCourse1, int daysCourse2, int daysCourse3, Degree degreeProgram) {
        
int daysCourse[3] = {daysCourse1, daysCourse2, daysCourse3};
        
classRosterArray[numStudents] = new Student(studentId, firstName, lastName, emailAddress, yearsOld, daysCourse, degreeProgram);
};

//ave days
void Roster::printAverageDaysInCourse(string studentId) {
bool found = false;
for (int i = 0; i <= ind; i++) {
    if (this-classRosterArray[i]->getId() == studentId) {
//student found
found = true;
double* daysCourse = classRosterArray[i]->getDays();
cout << "Average days in a course for " << studentId << " is " << (daysCourse[0] + daysCourse[1] + daysCourse[2]) / 3 << endl;
    }
}
}

//inv email addresses
Roster::printInvalidEmails() {
    cout << "Invalid emails: " << endl;
    for (int i = 0; i <= ind; i++) {
        cout << "Student ID: " << classStudentArray[i]->getId() << ": ";
        bool any = false;
        double* daysCourse = classStudentArray[i]->getDays();
        for (int j = 0; j < Student::classStudentArray; j++) {
            if (daysCourse[j] < 0) {
                any = true;
                cout << p[j] << " ";
            }
        }
        if (!any) cout << "None";
        cout << "\n";
    }
}


//my degree idk ???
Roster::printByDegreeProgram(Degree degreeProgram) {
    cout << "Degree programs: " << myDegree[degreeProgram] << endl;
    for (int i = 0; i <= ind; i++) {
        if (this->ClassRosterArray[i]->getDegree() == degreeProgram) this->classRosterArray[i]->print();
    }
}

// destroy every booooooookk
Roster::~Roster()
{
    for (int i = 0; i < numStudents; i++) {
        delete this->classRosterArray[i];
    }
    delete this;
}

#endif

/*/*

        classRosterArray[ind] = new Student();

        int i = studentData.find(",");
        studentId = studentData.substr(0, i);
        classRosterArray[ind]->setId(studentId);

        int d = i + 1;
        i = studentData.find(",", d);
        firstName = studentData.substr(d, i - d);
        classRosterArray[ind]->setFName(firstName);

        d = i + 1;
        i = studentData.find(",", d);
        lastName = studentData.substr(d, i - d);
        classRosterArray[ind]->setLName(lastName);

        d = i + 1;
        i = studentData.find(",", d);
        emailAddress = studentData.substr(d, i - d);
        classRosterArray[ind]->setEmail(emailAddress);

        d = i + 1;
        i = studentData.find(",", d);
        yearsOld = stoi(studentData.substr(d, i - d));
        classRosterArray[ind]->setAge(yearsOld);

        d = i + 1;
        i = studentData.find(",", d);
        daysCourse1 = stoi(studentData.substr(d, i - d));
    

        d = i + 1;
        i = studentData.find(",", d);
        daysCourse2 = stoi(studentData.substr(d, i - d));
    

        d = i + 1;
        i = studentData.find(",", d);
        daysCourse3 = stoi(studentData.substr(d, i - d));
        classRosterArray[ind]->setDays(daysCourse1, daysCourse2, daysCourse3);

        d = i + 1;
        i = studentData.find(",", d);
        string type = studentData.substr(d, i - d);
        if (type == "Software") {
            classRosterArray[ind]->setDegree(Software);
        }
        else if (type == "Security") {
            classRosterArray[ind]->setDegree(Security);
        }
        else if (type == "Network"){
            classRosterArray[ind]->setDegree(Network);
        }
        else {
            cout << "Degree does not exist" << endl;
        }
        ind++;

    }
    return;
    }
*/