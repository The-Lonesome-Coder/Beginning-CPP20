module lion;

import <iostream>;


void Lion::who() const
{
    std::cout << "I am a lion.\n";
    Animal::who();
}