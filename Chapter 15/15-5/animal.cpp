module animal;

import <format>;
import <iostream>;

// Constructor
Animal::Animal(std::string_view name, const unsigned int& weight)
    : m_name { name }, m_weight { weight } {};


// Return a string containing name and weight
std::string Animal::who() const
{
    return std::format("My name is: Woolly {}.\nI weight: {}", getName(), getWeight());
}


// Getter
std::string Animal::getName() const
{
    return m_name;
}


unsigned int Animal::getWeight() const
{
    return m_weight;
}


// Setter
void Animal::setName(std::string_view newName)
{
    m_name = newName;
}


void Animal::setWeight(const unsigned int& newWeight)
{
    m_weight = newWeight;
}