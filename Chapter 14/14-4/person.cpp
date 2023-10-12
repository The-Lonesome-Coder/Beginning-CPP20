module person;

import <format>;
import <iostream>;


// Constructor
Person::Person(std::string_view name, std::string_view gender, const unsigned int age)
    : m_name { name }, m_gender { gender }, m_age { age } {};


// Copy constructor
Person::Person(const Person& anotherPerson)
    : m_name { anotherPerson.m_name }, m_gender { anotherPerson.m_gender }, m_age { anotherPerson.m_age } {};


// Copy assignment
Person& Person::operator = (const Person& anotherPerson)
{
    if (this != &anotherPerson)
    {
        m_name = anotherPerson.m_name;
        m_gender = anotherPerson.m_gender;
        m_age = anotherPerson.m_age;
    }

    return *this;
}


// Getters
std::string_view Person::getName() const
{
    return m_name;
}


std::string_view Person::getGender() const
{
    return m_gender;
}


int Person::getAge() const
{
    return m_age;
}


// Setters
void Person::setAge(const int& newAge)
{
    m_age = newAge;
}


// Member function
void Person::who() const
{
    std::cout << std::format("Thy name is {}. {}, {} years old.\n", getName(), getGender(), getAge());
}


std::ostream& operator << (std::ostream& stream, const Person& person)
{
    stream << std::format("Thy name is {}. {}, {} years old.\n", person.getName(), person.getGender(), person.getAge());

    return stream;
}