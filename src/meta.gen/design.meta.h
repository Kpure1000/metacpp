#ifndef DESIGN_META_H
#define DESIGN_META_H
#include "../design.h"

namespace meta
{

    template <>
    std::string getClassName<Student>(Student *)
    {
        return "Student";
    }

    class meta_Student
    {
    public:
        // calss
        static std::string get_className()
        {
            return "Student";
        }
        // field 'name'
        static Any get_name(Any instance)
        {
            return static_cast<Any>(&(static_cast<Student *>(instance)->name));
        }
        static void set_name(Any instance, Any name)
        {
            static_cast<Student *>(instance)->name = *static_cast<std::string*>(name);
        }
        static std::string get_typeName_name()
        {
            return "std::string";
        }
        static std::string get_fieldName_name()
        {
            return "name";
        }
        static bool is_array_name()
        {
            return false;
        }
        constexpr static size_t get_typeID_name()
        {
            return 1;
        }
        // field 'number'
        static Any get_number(Any instance)
        {
            return static_cast<Any>(&(static_cast<Student *>(instance)->name));
        }
        static void set_number(Any instance, Any number)
        {
            static_cast<Student *>(instance)->number = *static_cast<uint32_t*>(number);
        }
        static std::string get_typeName_number()
        {
            return "uint32_t";
        }
        static std::string get_fieldName_number()
        {
            return "number";
        }
        static bool is_array_number()
        {
            return false;
        }
        constexpr static size_t get_typeID_number()
        {
            return 2;
        }

        friend Field;

        static void Register()
        {
            MetaRegister::

            // field 'name' register
            MetaRegister::field_register(meta_Student::get_className(), new Field(
                new FieldFunc(
                    meta_Student::get_name,
                    meta_Student::set_name,
                    meta_Student::get_typeName_name,
                    meta_Student::get_fieldName_name,
                    meta_Student::is_array_name,
                    meta_Student::get_typeID_name
                )
            ));
            // field 'number' register
            MetaRegister::field_register(meta_Student::get_className(), new Field(
                new FieldFunc(
                    meta_Student::get_number,
                    meta_Student::set_number,
                    meta_Student::get_typeName_number,
                    meta_Student::get_fieldName_number,
                    meta_Student::is_array_number,
                    meta_Student::get_typeID_number
                )
            ));
        }
    };


} // namespace meta::school

#endif 