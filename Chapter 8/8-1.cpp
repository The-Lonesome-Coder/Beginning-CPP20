#include <format>
#include <iostream>


bool year(const int &y)
{
    return (y >= 1970 && y <= 2023) ? true : false;
}


bool month(const int &m)
{
    return (m >= 1 && m <= 12) ? true : false;
}


bool is_leap(const int &y)
{
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? true : false;
}


bool day(const int &y, const int &m, const int &d)
{
    switch (m)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return (d >= 1 && d <= 31) ? true: false;

        case 4: case 6: case 9: case 11:
            return (d >= 1 && d <= 30) ? true : false;

        case 2:
            if (is_leap(y))
            {
                return (d >= 1 && d <= 29) ? true : false;
            }
            else
            {
                return (d >= 1 && d <= 28) ? true : false;
            }
        default:
            return false;
    }
}


bool validate_input(const int &y, const int &m, const int &d)
{
    return (year(y) && month(m) && day(y, m, d)) ? true : false;
}


int main(void)
{
    int year = 0, month = 0, day = 0;

    std::cout << "Please enter your birth year: ";
    std::cin >> year;

    std::cout << "Please enter your birth month: ";
    std::cin >> month;

    std::cout << "Please enter your birth day: ";
    std::cin >> day;

    if (validate_input(year, month, day))
    {
        std::cout << std::format("You were born on {}/{}/{}.", day, month, year)
                  << std::endl;

        return 0;
    }
    else
    {
        std::cout << "Invalid input. Please retry."
                  << std::endl;

        return 1;
    }
}