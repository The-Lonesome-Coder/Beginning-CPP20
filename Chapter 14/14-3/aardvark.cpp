module aardvark;

import <iostream>;


void Aardvark::who() const
{
    std::cout << "I am an aardvark.\n";
    Animal::who();
}