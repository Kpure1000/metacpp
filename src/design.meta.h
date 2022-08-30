
#include "design.h"

namespace meta::school
{
    class meta_Student
    {
    public:
        static void set_name(::school::Student *instance, std::string *name)
        {
            instance->name = *name;
        }
        static std::string *get_name(::school::Student *instance)
        {
            return &(instance->name);
        }
        static void set_number(::school::Student *instance, uint32_t* number)
        {
            instance->number = *number;
        }
        static uint32_t *get_number(::school::Student *instance)
        {
            return &(instance->number);
        }
    };


} // namespace meta::school

namespace meta
{
    
    template<>
    Type getType<::school::Student>(::school::Student* instance)
    {
        return Type("Student");
    }

    template<>
    Type getType<::school::Class>(::school::Class* instance)
    {
        return Type("Class");
    }

} // namespace meta

