/* 
 * File:   softwareStudent.h
 * Author: Parker Lee
 *
 * Created on January 7, 2020, 10:38 AM
 */

#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student {
    protected:
        Degree degree = SOFTWARE;
    
    public:
        SoftwareStudent(string studentID, string firstName, string lastName, string email, int age, int* numDays, Degree degree);
        Degree getDegreeProgram() override;
        void print() override;
};

#endif /* SOFTWARESTUDENT_H */

