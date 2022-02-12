// ************************EIGHTY CHARACTER CODING AREA*************************// LANDSCAPE COMMENT SECTION LENGTH
/*
                 _______.		main.cpp
   ______		| .   . |\			Driver program to test dice_rng.cpp and
  /     /\		|   .   |.\		dice_rng.hpp. Auto keyword since C++11.
 /  '  /  \		| .   . |.'|
/_____/. . \	|_______|.'|
\ . . \    /	 \ ' .   \'|
 \ . . \  /		  \____'__\|
  \_____\/
*/

#include "dice_rng.h"
#include <iostream>

int main()
{
    DiceRNG d;

    std::cout << "1 ROLL:\t" << d() << std::endl;
    std::cout << "1 ROLL:\t" << d.roll() << std::endl;

    std::cout << "5 ROLLS:\t";
    for (auto x : d(5))
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    return 0;
}

