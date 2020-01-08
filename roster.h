/* 
 * File:   roster.h
 * Author: Parker Lee
 *
 * Created on January 7, 2020, 10:39 AM
 */

#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <array>

class Roster {
protected:
    Student *classRosterArray[5];
    
public:    
    void add(string studentID, string firstName, string lastName, string email, int age, int num1, int num2, int num3, Degree degree);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(Degree degree);
    
    int iterator = 0;
    
    ~Roster();
};

#endif /* ROSTER_H */

