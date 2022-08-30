#include "all_meta.h"


int main(int argc, char const *argv[])
{
    school::Student stu("Iris", 1);
    auto type = meta::getType(&stu);
    std::cout << type.get_TypeName() << std::endl;
    std::cout << *(meta::school::meta_Student::get_name(&stu)) << std::endl;
    return 0;
}
