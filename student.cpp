/* 
 * File:   student.cpp
 * Author: Parker Lee
 *
 * Created on January 7, 2020, 10:31 AM
 */

#include "student.h"
#include <iostream>
using namespace std;

// Access functions
string Student::getStudentID() const {
    return studentID;
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

string Student::getEmail() const {
    return email;
}

int Student::getAge() const {
    return age;
}

int *Student::getNumDays() {
    return numDays;
}

// Mutator functions
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string email) {
    this->email = email;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setNumDays(int day0, int day1, int day2) {
    Student::numDays[0] = day0;
    Student::numDays[1] = day1;
    Student::numDays[2] = day2;
}

void Student::setDegree(Degree degree) {
    this->degree = degree;
}

// Constructors
Student::Student(string studentID, string firstName, string lastName, string email, int age, int* numDays, Degree degree) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->numDays[0] = numDays[0];
    this->numDays[1] = numDays[1];
    this->numDays[2] = numDays[2];
}

// Function to print specific student data
void Student::print() {}

// Destructor
Student::~Student() {}
