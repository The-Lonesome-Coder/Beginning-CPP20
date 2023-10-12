export module person;

import <ostream>;
import <string>;
import <string_view>;


export class Person
{
    public:
        // Constructor
        Person() = default;
        Person(std::string_view name, std::string_view gender, const unsigned int age);

        // Copy constructor
        Person(const Person& anotherPerson);

        // Destructor
        ~Person() {};

        // Copy assignment
        Person& operator = (const Person& anotherPerson);

        // Getter
        std::string_view getName() const;
        std::string_view getGender() const;
        int getAge() const;

        // Setter
        void setAge(const int& newAge);

        // Member function
        void who() const;

    private:
        std::string m_name;
        std::string m_gender;
        unsigned int m_age;
};


export std::ostream& operator << (std::ostream& stream, const Person& person);