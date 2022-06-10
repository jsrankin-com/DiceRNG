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

    std::cout << "One roll:\t" << d() << '\n';
    std::cout << "One roll:\t" << d.Roll() << '\n';

    std::cout << "Five rolls:\t";
    for (auto x : d(5))
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    std::cout << "Five rolls:\t";
    for (auto x : d.Roll(5))
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    std::cout << "Risk test:" << '\n';

    int attacking_army = 50;
    int defending_army = 50;

    while (0 < attacking_army && 0 < defending_army)
    {
        //Set attacking dice to 3 or less
        std::vector<int> att_rolls = (attacking_army < 3) 
            ? d.Roll(attacking_army) 
            : d.Roll(3);

        //Set defending dice to 2 or 1
        std::vector<int> def_rolls = (defending_army == 1) 
            ? d.Roll(defending_army)
            : d.Roll(2);

        //Sort to compare best Rolls
        std::sort(att_rolls.begin(), att_rolls.end(), std::greater<>());
        std::sort(def_rolls.begin(), def_rolls.end(), std::greater<>());

        int iterations = (att_rolls.size() < def_rolls.size())
            ? att_rolls.size()
            : def_rolls.size();

        for (int i = 0; i < iterations; ++i)
        {
            //Defender wins if rolls are equal
            if (def_rolls[i] < att_rolls[i])
            {
                --defending_army;
                std::cout << "ATTACKER WON" << '\n';
            }
            else {
                --attacking_army;
                std::cout << "ATTACKER LOST" << '\n';
            }
        }
    }

    (attacking_army < defending_army)
        ? std::cout << "\nATTACKER LOST THE BATTLE\n"
        : std::cout << "\nATTACKER WON THE BATTLE\n";

    std::cout << "ATTACKING ARMY: " << attacking_army
        << "\nDEFENDING ARMY: " << defending_army << std::endl;

    std::cout << "\nPress ENTER key to continue...";
    std::cin.get();
    std::cout << std::endl;

    return 0;
}

