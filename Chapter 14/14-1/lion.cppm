export module lion;

import <string_view>;
import animal;


export class Lion : public virtual Animal
{
    public:
        using Animal::Animal;

        // Constructor
        Lion(std::string_view name, const int& weight);

        // Copy constructor
        Lion(const Lion& anotherLion);

        // Destructor
        ~Lion() {};
};