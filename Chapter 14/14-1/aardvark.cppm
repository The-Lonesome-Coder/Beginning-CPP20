export module aardvark;

import <string_view>;

import animal;


export class Aardvark : public virtual Animal
{
    public:
        using Animal::Animal;

        // Constructor
        Aardvark(std::string_view name, const int& weight);

        // Copy constructor
        Aardvark(const Aardvark& anotherAardvark);

        // Destructor
        ~Aardvark() {};
};