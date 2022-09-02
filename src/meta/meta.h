#ifndef META_H
#define META_H
#include <iostream>
#include <vector>

#ifndef META_CLASS
#define META_CLASS(name) namespace meta { class meta_##name; }
#endif

#ifndef META_ACCESS
#define META_ACCESS(name) friend ::meta::meta_##name;
#endif

namespace meta
{

    using Any = void *;

    using GetFunc       = std::function< Any         ( Any      ) >;
    using SetFunc       = std::function< void        ( Any, Any ) >;
    using GetNameFunc   = std::function< std::string (          ) >;
    using IsArrayFunc   = std::function< bool        (          ) >; 
    using GetTypeIDFunc = std::function< size_t      (          ) >; 

    using FieldFunc = std::tuple<
        GetFunc,        // get_xxx
        SetFunc,        // set_xxx
        GetNameFunc,    // get_typeName
        GetNameFunc,    // get_fieldName
        IsArrayFunc,    // is_array
        GetTypeIDFunc   // get_TypeID_xxx
    >;

    using ClassFunc = std::tuple<
        GetNameFunc    // get_className
    >;

    class Field
    {
    public:
        // Field() : fieldFunc(nullptr) {}
        Field(FieldFunc *fieldFunc) : fieldFunc(fieldFunc) {}

        inline Any get(Any instance) { return std::get<0>(*fieldFunc)(instance); }

        inline void set(Any instance, Any value) { std::get<1>(*fieldFunc)(instance, value); }

        inline std::string get_typeName() { return std::get<2>(*fieldFunc)(); }

        inline std::string get_name() { return std::get<3>(*fieldFunc)(); }

        inline bool is_array() { return std::get<4>(*fieldFunc)(); }

        inline constexpr size_t get_typeID() { return std::get<5>(*fieldFunc)(); }

    private:

        FieldFunc* fieldFunc;
    };

    class Class
    {
    public:
        Class(ClassFunc *classFunc) : classFunc(classFunc) {}
        inline std::string get_className() { return std::get<0>(*classFunc)(); }

    private:
        ClassFunc *classFunc;
    };

    /**
     * Type can be a class or basic type
     */
    class Type
    {
    public:
        Type();

        std::string get_name()
        {
            return m_name;
        }

        Field* get_field_byName(std::string const& name);

        std::vector<Field *> *get_fields() { return &m_fields; }

    private:
        Type(std::string const &name);

        std::string m_name;

        std::vector<Field*> m_fields;

    public:
        static Type* newByClassName(std::string const& name)
        {
            return new Type(name);
        }

    };

    class MetaInstance
    {
    public:
        Type type;
        Any instance;
    };

    class MetaRegister
    {
    public:
        void Register();

    public:
        static void class_register(std::string const& name, Class* field);
        static void field_register(std::string const& name, Field* field);
    };

    template <typename classT>
    std::string getClassName(classT *)
    {
        return "unkown";
    }

} // namespace meta

#endif