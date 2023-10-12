import <iostream>;
import <vector>;

import employee;
import executive;


int main()
{

    std::vector<Employee> employees
    {
        { "Sam Smith", "Male", 32, 123456 },
        { "Phoenix Ward", "Female", 33, 123457 },
        { "Braden Davidson", "Male", 33, 123458 }
    };

    for (const auto& employee : employees)
    {
        employee.who();
    }


    std::vector<Executive> executives
    {
        { "Sam Smith", "Male", 32, 123456 },
        { "Phoenix Ward", "Female", 33, 123457 },
        { "Braden Davidson", "Male", 33, 123458 }
    };

    for (const auto& executive : executives)
    {
        executive.who();
    }

    return 0;
}