export module aardvark;

import <string_view>;

import animal;


export class Aardvark : public virtual Animal
{
    public:
        using Animal::Animal;

        // Constructor
        Aardvark(std::string_view name, const int& weight);

        // Destructor
        ~Aardvark() {};

        // Member function
        void who() const;
};