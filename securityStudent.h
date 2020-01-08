/* 
 * File:   securityStudent.h
 * Author: Parker Lee
 *
 * Created on January 7, 2020, 10:37 AM
 */

#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "degree.h"
#include "student.h"

class SecurityStudent : public Student {
    protected:
        Degree degree = SECURITY;
    
    public:
        SecurityStudent(string studentID, string firstName, string lastName, string email, int age, int* numDays, Degree degree);
        Degree getDegreeProgram() override;
        void print() override;
};

#endif /* SECURITYSTUDENT_H */

