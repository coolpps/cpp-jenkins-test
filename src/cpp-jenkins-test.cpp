#include <iostream>

#include "../include/mathTest.hpp"
#include "../include/cpp-jenkins-test.hpp"

int main(int argc, char* argv[])
{

    MathTest<int> math_int;
    std::cout << "1 + 2 =" << math_int.add(1, 2) << std::endl;
    std::cout << "1 - 2 =" << math_int.sub(1, 2) << std::endl;
    std::cout << "1 / 2 =" << math_int.div(1, 2) << std::endl;


    MathTest<int> math_int2(2);
    std::cout << math_int2.pow(10) << std::endl;
    return 0;
}