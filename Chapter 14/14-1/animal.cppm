export module animal;

import <compare>;
import <ostream>;
import <string>;
import <string_view>;


export class Animal
{
    public:
        // Constructor
        Animal(std::string_view name, const int& weight);

        // Copy constructor
        Animal(const Animal& anotherAnimal);

        // Copy assignment
        Animal& operator = (Animal& anotherAnimal);

        // Destructor
        ~Animal() {};

        // Operator overload
        std::partial_ordering operator <=> (const Animal& anotherAnimal) const;
        bool operator == (const Animal& anotherAnimal) const;

        // Getter
        int getWeight() const;
        std::string getName() const;

        // Setter
        void setWeight(const int& newWeight);
        void setName(std::string_view newName);

        // Member function
        void who() const;


    private:
        std::string m_name;
        int m_weight;
};


export std::ostream& operator << (std::ostream& stream, const Animal& animal);