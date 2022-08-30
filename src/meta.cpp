#include "meta.h"

namespace meta
{
    Field* Type::get_field_byName(std::string const& name)
    {
        auto ret = std::find_if(fields.begin(), fields.end(), [&name](auto const& field)
        {
            return field.name == name;
        });
        return ret != fields.end() ? *ret : nullptr;
    }
} // namespace meta
