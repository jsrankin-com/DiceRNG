# DiceRNG
Creates an object that acts as a cubical 6-sided die. The die can be rolled by either calling the public roll function or the overloaded parentheses. If a number is supplied it will roll the die that many times and return the results as a vector of integers

# How to build
https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/build/how-to-create-a-cpp-project-from-existing-code.md

## References
*[https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution](https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution)
*[https://www.cplusplus.com/reference/vector/vector/reserve/](https://www.cplusplus.com/reference/vector/vector/reserve/)

## Art by valkyrie
+[https://www.asciiart.eu/miscellaneous/dice](https://www.asciiart.eu/miscellaneous/dice)

## Author
Jeffrey S. Rankin
-[http://jsrankin.com](http://jsrankin.com)
-[admin@jsrankin.com](admin@jsrankin.com)

```cpp
int main()
{
    DiceRNG d;

    std::cout << "One roll:\t" << d() << std::endl;
    std::cout << "One roll:\t" << d.roll() << std::endl;
    
    std::vector<int> rolls;
    rolls = d(5);
    
    std::cout << "Five rolls:\t";
    for (auto x : rolls)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;

    rolls = d.Roll(5);
    std::cout << "Five rolls:\t";
    for (auto x : rolls)
    {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
    
    return 0;
}
```
