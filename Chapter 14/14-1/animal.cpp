module animal;

import <format>;
import <iostream>;


// Constructor
Animal::Animal(std::string_view name, const int& weight)
    : m_name { name }, m_weight { weight } {};


// Copy constructor
Animal::Animal(const Animal& anotherAnimal)
    : m_name { anotherAnimal.m_name }, m_weight { anotherAnimal.m_weight } {};


// Copy Assignment
Animal& Animal::operator = (Animal& anotherAnimal)
{
    if (this != &anotherAnimal)
    {
        m_name = anotherAnimal.m_name;
        m_weight = anotherAnimal.m_weight;
    }

    return *this;
}


// Operator overload
std::partial_ordering Animal::operator <=> (const Animal& anotherAnimal) const
{
    return getWeight() <=> anotherAnimal.getWeight();
}


bool Animal::operator == (const Animal& anotherAnimal) const
{
    return getName() == anotherAnimal.getName() && getWeight() == anotherAnimal.getWeight();
}


std::ostream& operator << (std::ostream& stream, const Animal& animal)
{
    stream << std::format("Animal name: {};\nAnimal weight: {}.\n", animal.getName(), animal.getWeight());

    return stream;
}


// Getters
int Animal::getWeight() const
{
    return m_weight;
}


std::string Animal::getName() const
{
    return m_name;
}


// Setters
void Animal::setWeight(const int& newWeight)
{
    m_weight = newWeight;
}


void Animal::setName(std::string_view newName)
{
    m_name = newName;
}


// Get animal information
void Animal::who() const
{
    std::cout << std::format("Animal name: {};\nAnimal weight: {}.\n", getName(), getWeight());
}