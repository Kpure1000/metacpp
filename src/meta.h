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

        Field* get_field_byName(std::string const& name);

    private:
        Type(std::string const &name) : name(name)
        {
        }

        std::vector<Field*> fields;

        template <typename T>
        friend Type get_type(T *);

    };

    class Field
    {
    public:
        std::string get_name() { return name; }
        Type get_type() { return type; }

    private:
        std::string name;

        Type type;
    };

    // class Method
    // {
    //     std::string name;

    //     Type return_type;
    //     std::vector<Type> args_type;
    // };

    class Class
    {
    public:
        std::vector<Field> get_fields()
        {
            return fields;
        }
    private:
        std::vector<Field> fields;
        // std::vector<Method> methods;
    };

    class MetaInstance
    {
    public:
        Type type;
    };


    template <typename T>
    inline Type get_type(T *instance)
    {
        return Type();
    }

    template<>
    inline Type get_type<bool>(bool* instance)
    {
        return Type("bool");
    }
    
    template<>
    inline Type get_type<uint8_t>(uint8_t* instance)
    {
        return Type("uint8_t");
    }
    
    template<>
    inline Type get_type<uint16_t>(uint16_t* instance)
    {
        return Type("uint16_t");
    }
    
    template<>
    inline Type get_type<uint32_t>(uint32_t* instance)
    {
        return Type("uint32_t");
    }
    
    template<>
    inline Type get_type<uint64_t>(uint64_t* instance)
    {
        return Type("uint64_t");
    }
    
    template<>
    inline Type get_type<int8_t>(int8_t* instance)
    {
        return Type("int8_t");
    }
    
    template<>
    inline Type get_type<int16_t>(int16_t* instance)
    {
        return Type("int16_t");
    }
    
    template<>
    inline Type get_type<int32_t>(int32_t* instance)
    {
        return Type("int32_t");
    }
    
    template<>
    inline Type get_type<int64_t>(int64_t* instance)
    {
        return Type("int64_t");
    }
    
    template<>
    inline Type get_type<float>(float* instance)
    {
        return Type("float");
    }

    template<>
    inline Type get_type<double>(double* instance)
    {
        return Type("double");
    }

    template<>
    inline Type get_type<std::string>(std::string* instance)
    {
        return Type("std::string");
    }

    template<>
    inline Type get_type<std::vector<int>>(std::vector<int>* instance)
    {
        return Type("std::vector<int>");
    }


} // namespace meta

#endif