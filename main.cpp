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
#include "/tests/risk.cpp"
#include <iostream>

template <class T>
T ReturnSmaller(T lhs, T rhs)
{
    return lhs < rhs ? lhs : rhs;
}

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

    std::cout << "Risk test:" << std::endl;
    std::vector<int> attRoles;
    std::vector<int> defRoles;

    int attacking_army = 50;
    int defending_army = 50;

    while (0 < attacking_army && 0 < defending_army)
    {
        //Set attacking dice 3 or less
        if (attacking_army < 3)
        {
            attRoles = d.Roll(attacking_army);
        }
        else
        {
            attRoles = d.Roll(3);
        }

        //Set defending dice 2 or 1
        if (defending_army == 1)
        {
            defRoles = d.Roll(1);
        }
        else {
            defRoles = d.Roll(2);
        }

        //Sort to compare best Rolls
        std::sort(attRoles.begin(), attRoles.end(), std::greater<>());
        std::sort(defRoles.begin(), defRoles.end(), std::greater<>());

        int iterations = ReturnSmaller(attRoles.size(), defRoles.size());
        for (int i = 0; i < iterations; ++i)
        {
            //Defender wins if Rolls are equal or higher
            if (defRoles[i] < attRoles[i])
            {
                --defending_army;
                std::cout << "ATTACKER WON" << std::endl;
            }
            else {
                --attacking_army;
                std::cout << "ATTACKER LOST" << std::endl;
            }
        }
    }

    if (attacking_army < defending_army)
    {
        std::cout << "ATTACKER LOST THE BATTLE\n";
    }
    else
    {
        std::cout << "ATTACKER WON THE BATTLE\n";
    }
    std::cout << "ATTACKING ARMY: " << attacking_army
        << "\nDEFENDING ARMY: " << defending_army << std::endl;

    std::cout << "\nPress ENTER key to continue...";
    std::cin.get();
    std::cout << std::endl;

    return 0;
}

