export module animal.sheep;

import animal;


export class Sheep : public Animal
{
    public:
        // Constructor
        using Animal::Animal;

        Sheep(std::string_view name, const unsigned int& weight);
        Sheep(std::string_view name, const unsigned int& weight, const unsigned int& woolWeight);

        // Destructor
        virtual ~Sheep() {};

        // Return a string containing name and weight - override
        virtual std::string who() const;

        // Return a string representing the sound the animal make - override
        virtual std::string_view sound() const override;

        // Return wool weight and set it to 0
        unsigned int shear();


    protected:
        // Getter
        unsigned int getWoolWeight() const;


    private:
        unsigned int m_woolWeight;
};