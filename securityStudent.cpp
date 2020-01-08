/* 
 * File:   securityStudent.coo
 * Author: Parker Lee
 *
 * Created on January 7, 2020, 10:31 AM
 */

#include "securityStudent.h"
#include <iostream>

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int *numDays, Degree degree) : 
    Student(studentID, firstName, lastName, email, age, numDays, degree) {
    this->degree = degree;
}

Degree SecurityStudent::getDegreeProgram() {
    return degree;
}

void SecurityStudent::print() {
    cout << getStudentID();
    cout << "\tFirst Name: " << getFirstName();
    cout << "\tLast Name: " << getLastName();
    cout << "\tAge: " << getAge();
    
    int* day = getNumDays();
    cout << "\t\tdaysInCourse: " << "{ " << day[0] << ", " << day[1] << ", " << day[2] << " }";
    
    cout << "\tDegree Program: Security" << endl;
}





