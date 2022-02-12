// ************************EIGHTY CHARACTER CODING AREA*************************// LANDSCAPE COMMENT SECTION LENGTH
/*
		 _______.	dice_rng.cpp
   ______	| .   . |\	dice_rng.h
  /     /\	|   .   |.\		Creates an object that acts as a cubical
 /  '  /  \	| .   . |.'|	6-sided die. The die can be rolled by either
/_____/. . \	|_______|.'|	calling the public roll function or the
\ . . \    / 	 \ ' .   \'|	overloaded parentheses. If a number is supplied
 \ . . \  /	  \____'__\|	it will roll the die that many times and return
  \_____\/			the results as a vector of integers.
*/

#include "dice_rng.h"
#include <iostream>

DiceRNG::DiceRNG()
{
	//Seed with random device
	generator = std::mt19937(device());
	distribution = std::uniform_int_distribution<int>(1, 6);
}

int DiceRNG::operator()()
{
	return DiceRNG::Roll();
}

std::vector<int> DiceRNG::operator()(int n)
{
	return DiceRNG::Roll(n);
}

//Returns one roll as an int
int DiceRNG::Roll()
{
	return distribution(generator);
}

//Returns a vector of rolls as ints
std::vector<int> DiceRNG::Roll(int n)
{
	std::vector<int> ret;

	try
	{
		//Try to reserve the memory
		if (n < ret.max_size() && n > 0)
			ret.reserve(n);

		for (; 0 < n; --n)
			ret.emplace_back(distribution(generator));
	}
	catch (const std::bad_alloc& ba)
	{
		std::cerr << "Bad allocation: " << ba.what() << '\n';
	}
	catch (const std::length_error& le) {
		std::cerr << "Length error: " << le.what() << '\n';
	}

	return ret;
}

/*
References:
https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
https://www.cplusplus.com/reference/vector/vector/reserve/

Art by valkyrie
https://www.asciiart.eu/miscellaneous/dice

Author:
	Jeffrey S. Rankin
	http://jsrankin.com
	admin@jsrankin.com
*/

