#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"
#ifndef ROSTER_H
#define ROSTER_H

using namespace std;

Roster::Roster() {
//initialization
Student students[5];
Student* classRosterArray[5];

//array of student objects
Student students[5] = {
    {"A1","John","Smith","John1989@gm ail.com",20,{30,35,40},"SECURITY"},
    {"A2","Suzan","Erickson","Erickson_1990@gmailcom",19,{50,30,40},"NETWORK"},
    {"A3","Jack","Napoli","The_lawyer99yahoo.com",19,{20,40,33},"SOFTWARE"},
    {"A4","Erin","Black","Erin.black@comcast.net",22,{50,58,40},"SECURITY"},
    {"A5","Ana","Escobedo","myemailaddress@gmail.com",23,{20,21,22},"SOFTWARE"}
};

//populate array w array of student objects
for (int i = 0; i <= 5; i++){
classRosterArray[i] = &students[i];
}

//print vals w pointers
for (int i = 0; i <= 5; i++){
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


int main() {
Roster myRoster;
system("pause>0");
return 0;
}

#endif

