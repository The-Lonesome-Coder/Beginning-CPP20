export module animal;

import <string>;
import <string_view>;


// Virtual base class
export class Animal
{
    public:
        // Return a string containing name and weight
        std::string who() const;

        // Getter
        std::string getName() const;
        int getWeight() const;

        // Return a string representing the sound the animal make - pure virtual function
        virtual std::string_view sound() const = 0;

        // Constructor
        Animal(std::string_view name, const int& weight);

        // Destructor
        virtual ~Animal() {};

        // Setter
        void setName(std::string_view newName);
        void setWeight(const int& newWeight);

    private:
        std::string m_name;
        int m_weight;
};