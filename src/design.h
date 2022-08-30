#ifndef DESIGN_H
#define DESIGN_H

#include <memory>
#include <iostream>
#include <vector>

#include "meta.h"

namespace school
{
    META()
    class Student
    {
    public:
        Student(std::string const &name, uint32_t number)
            : name(name), number(number) {}

        META()
        std::string name;
        
        META()
        uint32_t number;

        bool is_male()
        {
            return 0x01 & number;
        }
    };

    META()
    class Class
    {
    public:
    
        META()
        std::vector<Student *> students;

        META()
        std::shared_ptr<Student> monitor_ref;

        Student *at(int index)
        {
            return students.at(index);
        }
    };

} // namespace school

#endif