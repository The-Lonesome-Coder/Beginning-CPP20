export module animal.cow;

import animal;


export class Cow : public Animal
{
    public:
        // Constructor
        using Animal::Animal;

        // Destructor
        virtual ~Cow() {};

        // Return a string containing name - override
        virtual std::string who() const override;

        // Return a string representing the sound the animal make - override
        virtual std::string_view sound() const override;
};