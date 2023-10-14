export module animal.dog;

import animal;


export class Dog : public virtual Animal
{
    public:
        // Constructor
        using Animal::Animal;

        // Destructor
        virtual ~Dog() {};

        // Return a string representing the sound the animal make - pure virtual function
        virtual std::string_view sound() const override;
};