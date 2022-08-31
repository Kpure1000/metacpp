#ifndef META_H
#define META_H
#include <iostream>
#include <vector>

#ifndef META
#define META()
#endif

namespace meta
{

    class Field;

    /**
     * Type can be a class or basic type
     */
    class Type
    {
    private:
        std::string name;

    public:
        Type() : name("unknown")
        {
        }

        std::string get_name()
        {
            return name;
        }

        Type* get_field_byName(std::string const& name);

    private:
        Type(std::string const &name) : name(name)
        {
        }

        std::vector<Type*> fields;

    };

    using Any = typename void*;

    class MetaInstance
    {
    public:
        Type type;
        Any instance;
    };

} // namespace meta

#endif