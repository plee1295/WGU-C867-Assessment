/* 
 * File:   networkStudent.h
 * Author: Parker Lee
 *
 * Created on January 7, 2020, 10:36 AM
 */

#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "degree.h"
#include "student.h"

class NetworkStudent : public Student {
    protected:
        Degree degree = NETWORK;
    
    public:
        NetworkStudent(string studentID, string firstName, string lastName, string email, int age, int* numDays, Degree degree);
        Degree getDegreeProgram() override;
        void print() override;
};

#endif /* NETWORKSTUDENT_H */

