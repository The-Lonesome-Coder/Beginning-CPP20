export module animal.sheep;

import animal;


export class Sheep : public Animal
{
    public:
        // Constructor
        using Animal::Animal;

        // Destructor
        virtual ~Sheep() {};

        // Return a string containing name and weight - override
        virtual std::string who() const;

        // Return a string representing the sound the animal make - override
        virtual std::string_view sound() const override;
};