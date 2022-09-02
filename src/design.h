#ifndef DESIGN_H
#define DESIGN_H

#include <memory>
#include <iostream>
#include <vector>

#include "meta/meta.h"

META_CLASS(Student)

class Student
{
    META_ACCESS(Student)
public:
    Student(std::string const &name, uint32_t number)
        : name(name), number(number) {}

    bool is_male()
    {
        return 0x01 & number;
    }

private:
    std::string name;
    uint32_t number;
};

class Class
{
public:

    std::vector<Student *> students;

    std::shared_ptr<Student> monitor_ref;

    Student *at(int index)
    {
        return students.at(index);
    }
};

#endif