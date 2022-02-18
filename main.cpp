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

    std::cout << "Risk test:\t";
    std::vector<int> attackerRoles;
    std::vector<int> defenderRoles;

    int attacking_army = 50;
    int defending_army = 50;

    while (0 < attacking_army && 0 < defending_army)
    {
        //Set attacking dice 3 or less
        if (attacking_army < 3)
        {
            attackerRoles = d.Roll(attacking_army);
        }
        else
        {
            attackerRoles = d.Roll(3);
        }

        //Set defending dice 2 or 1
        if (defending_army == 1)
        {
            defenderRoles = d.Roll(1);
        }
        else {
            defenderRoles = d.Roll(2);
        }

        //Sort to compare best Rolls
        std::sort(attackerRoles.begin(), attackerRoles.end(), std::greater<>());
        std::sort(defenderRoles.begin(), defenderRoles.end(), std::greater<>());

        int iterations = ReturnSmaller(attackerRoles.size(), defenderRoles.size());
        for (int i = 0; i < iterations; ++i)
        {
            //Defender wins if Rolls are equal or higher
            if (defenderRoles[i] < attackerRoles[i])
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
        std::cout << "ATTACKER LOST THE BATTLE\n"
            << "ATTACKING ARMY: " << attacking_army
            << "DEFENDING ARMY: " << defending_army << std::endl;
    }
    else
    {
        std::cout << "ATTACKER WON THE BATTLE\n"
            << "ATTACKING ARMY: "<<attacking_army 
            << "DEFENDING ARMY: " << defending_army << std::endl;
    }

    std::cout << "\nPress ENTER key to continue...";
    std::cin.get();
    std::cout << std::endl;

    return 0;
}

