export module animal;

import <string>;
import <string_view>;


// Virtual base class
export class Animal
{
    public:
        // Constructor
        Animal(std::string_view name, const unsigned int& weight);

        // Destructor
        virtual ~Animal() {};

        // Return a string containing name and weight
        virtual std::string who() const;

        // Return a string representing the sound the animal make - pure virtual function
        virtual std::string_view sound() const = 0;


    protected:
        // Getter
        std::string getName() const;
        unsigned int getWeight() const;

        // Setter
        void setName(std::string_view newName);
        void setWeight(const unsigned int& newWeight);


    private:
        std::string m_name;
        unsigned int m_weight;
};