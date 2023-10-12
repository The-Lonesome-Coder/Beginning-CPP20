export module employee;

import person;


export class Employee : public Person
{
    public:
        using Person::Person;

        // Constructor
        Employee() = default;
        Employee(std::string_view name, std::string_view gender, unsigned int age, unsigned long long int number);

        // Getter
        unsigned long long int getPersonalNumber() const;

        // Member function
        void who() const;

    private:
        unsigned long long int m_personalNumber;
};