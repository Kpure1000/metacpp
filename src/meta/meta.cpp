#include "meta.h"

#include <map>
#include <unordered_map>

namespace meta
{

    const char* unknown_name = "unknown";

    std::multimap<std::string, Field*> meta_field_map;
    std::unordered_map<std::string, Class*> meta_class_map;
    
    Type::Type() : m_name(unknown_name) {}
    
    Type::Type(std::string const &name) : m_name(name)
    {
        auto fields = meta_field_map.equal_range(name);
        while (fields.first != fields.second)
        {
            // if( fields.first->second->get_name() == name )
                this->m_fields.emplace_back(fields.first->second);
            fields.first++;
        }
    }

    Field* Type::get_field_byName(std::string const& name)
    {
        auto ret = std::find_if(m_fields.begin(), m_fields.end(), [&name](auto const& field)
        {
            return field->get_name() == name;
        });
        return ret != m_fields.end() ? *ret : nullptr;
    }

    void MetaRegister::class_register(std::string const &name, Class *_class)
    {
        meta_class_map.insert({name, _class});
    }

    void MetaRegister::field_register(std::string const &name, Field *_field)
    {
        meta_field_map.insert({name, _field});
    }

} // namespace meta
