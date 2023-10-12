module employee;

import <format>;
import <iostream>;


Employee::Employee(std::string_view name, std::string_view gender, unsigned int age, unsigned long long int number)
    : Person { name, gender, age }, m_personalNumber { number } {};


unsigned long long int Employee::getPersonalNumber() const
{
    return m_personalNumber;
}


void Employee::who() const
{
    std::cout << std::format("{} is a {} employee, aged {}.\n", getName(), getGender(), getAge());
}