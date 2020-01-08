/* 
 * File:   student.h
 * Author: Parker Lee
 *
 * Created on January 7, 2020, 10:32 AM
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

using namespace std;

class Student {
protected: 
    string studentID;
    string firstName;
    string lastName;
    string email;
    
    int age;
    int numDays[3];
    
    Degree degree;
    
public:
    // Constructors       
    Student(string studentID, string firstName, string lastName, string email, int age, int* numDays, Degree degree);
    
    // Accessors (Getters)
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    int *getNumDays();
    
    // Mutators (Setters)
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setNumDays(int day0, int day1, int day2);
    void setDegree(Degree degree);
    
    // Virtual functions
    virtual void print();
    virtual Degree getDegreeProgram() = 0;
    
    // Destructor
    ~Student();
};

#endif /* STUDENT_H */

