export module animal.cow;

import animal;


export class Cow : public virtual Animal
{
    public:
        // Constructor
        using Animal::Animal;

        // Destructor
        virtual ~Cow() {};

        // Return a string representing the sound the animal make - pure virtual function
        virtual std::string_view sound() const override;
};