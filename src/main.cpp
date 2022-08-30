#include "all_meta.h"


int main(int argc, char const *argv[])
{
    school::Student stu("Iris", 1);
    std::cout << meta::get_type(&stu).get_name() << std::endl;
    std::cout << meta::get_type(meta::school::meta_Student::get_name(&stu)).get_name() << std::endl;

    auto type = meta::get_type(&stu);
    

    std::vector<int> dsa;
    meta::get_type(&dsa);
    return 0;
}
