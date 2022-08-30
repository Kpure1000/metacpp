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

        std::string get_TypeName()
        {
            return name;
        }

    private:
        Type(std::string const &name) : name(name)
        {
        }

        std::vector<Field*> fields;

        template <typename T>
        friend Type getType(T *);

    };

    class Field
    {
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
        std::vector<Field> fields;
        // std::vector<Method> methods;
    };

    class MetaInstance
    {
    public:
        Type type;
    };


    template <typename T>
    Type getType(T *instance)
    {
        return Type();
    }

    template<>
    Type getType<uint8_t>(uint8_t* instance)
    {
        return Type("uint8_t");
    }
    
    template<>
    Type getType<uint16_t>(uint16_t* instance)
    {
        return Type("uint16_t");
    }
    
    template<>
    Type getType<uint32_t>(uint32_t* instance)
    {
        return Type("uint32_t");
    }
    
    template<>
    Type getType<uint64_t>(uint64_t* instance)
    {
        return Type("uint64_t");
    }
    
    template<>
    Type getType<int8_t>(int8_t* instance)
    {
        return Type("int8_t");
    }
    
    template<>
    Type getType<int16_t>(int16_t* instance)
    {
        return Type("int16_t");
    }
    
    template<>
    Type getType<int32_t>(int32_t* instance)
    {
        return Type("int32_t");
    }
    
    template<>
    Type getType<int64_t>(int64_t* instance)
    {
        return Type("int64_t");
    }
    
    template<>
    Type getType<float>(float* instance)
    {
        return Type("float");
    }

    template<>
    Type getType<double>(double* instance)
    {
        return Type("double");
    }


} // namespace meta

#endif