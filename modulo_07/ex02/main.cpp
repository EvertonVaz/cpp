#include <iostream>
#include "Array.hpp"
#include "Fixed.hpp"

int main(int, char**)
{
    Array<Fixed> testFixed(3);
    for (int i = 0; i < 3; i++)
    {
        if (i == 1)
            testFixed[i] = 42.5f;
        else
            testFixed[i] = 42;
    }
    for (int i = 0; i < 4; i++)
    {
        try {
            std::cout << " Array: " << testFixed[i] << std::endl;
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }

    Array<std::string> testStr;
    testStr = Array<std::string>(3);
    for (int i = 0; i < 3; i++)
    {
        testStr[i] = "aoba";
    }
    for (int i = 0; i < 4; i++)
    {
        try {
            std::cout << " Array: " << testStr[i] << std::endl;
        } catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}