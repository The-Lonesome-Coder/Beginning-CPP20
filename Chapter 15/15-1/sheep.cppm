export module animal.sheep;

import animal;


export class Sheep : public virtual Animal
{
    public:
        // Constructor
        using Animal::Animal;

        // Destructor
        virtual ~Sheep() {};

        // Return a string representing the sound the animal make - pure virtual function
        virtual std::string_view sound() const override;
};