#include "meta.h"

#include <map>

namespace meta
{


    std::multimap<std::string, std::tuple<>> meta_field_map;


    Type* Type::get_field_byName(std::string const& name)
    {
        auto ret = std::find_if(fields.begin(), fields.end(), [&name](auto const& field)
        {
            return field->get_name() == name;
        });
        return ret != fields.end() ? *ret : nullptr;
    }
} // namespace meta
