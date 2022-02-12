// ************************EIGHTY CHARACTER CODING AREA*************************// LANDSCAPE COMMENT SECTION LENGTH
/*
               _______.     main.cpp
   ______     | .   . |\      Driver program to test dice_rng.cpp and 
  /     /\    |   .   |.\   dice_rng.hpp. Auto keyword since C++11.
 /  '  /  \   | .   . |.'|
/_____/. . \  |_______|.'|
\ . . \    /   \ ' .   \'|
 \ . . \  /     \____'__\|
  \_____\/
*/

#include "dice_rng.h"
#include <iostream>

int main()
{
    DiceRNG d;

    std::cout << "One roll:\t" << d() << std::endl;
    std::cout << "One roll:\t" << d.Roll() << std::endl;

    std::cout << "Five rolls:\t";
    for (auto x : d(5))
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    std::cout << "Five rolls:\t";
    for (auto x : d.Roll(5))
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    std::cout << "\nPress ENTER key to continue...";
    std::cin.get();
    std::cout << std::endl;

    return 0;
}

