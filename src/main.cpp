#include <iostream>
#include <map>
#include "meta.gen/all_meta.h"

#include "clang-c/Index.h"

int main(int argc, char const *argv[])
{
    auto meta_register = std::make_shared<meta::MetaRegister>();
    meta_register->Register();

    Student stu("Iris", 1);

    auto stu_className = meta::getClassName(&stu);

    auto type_stu = meta::Type::newByClassName(stu_className);

    std::cout << "type: " << type_stu->get_name() << std::endl;
    for (auto field : *type_stu->get_fields())
    {
        std::cout << "-field: "
                  << field->get_typeName() << std::endl;

    }

    auto index = clang_createIndex(0,1);
    auto f = clang_createTranslationUnitFromSourceFile(index, "design.h", 0, nullptr, 0, nullptr);
    

    return 0;
}
