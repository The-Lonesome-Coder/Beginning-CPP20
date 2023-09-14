#include <cmath>
#include <format>
#include <iostream>
#include <stdexcept>


int main(void)
{
    float total = 0.0F;

    std::cout << "Please enter an amount of money (from 0 to 10, two decimal places allowed): ";
    std::cin >> total;

    if (total < 0.0 || total > 10.0)
    {
        throw std::out_of_range("The input should be within 0 and 10.");

        return 1;
    }

    double temp = std::floor(total * 100) / 100;

    int quarter = 0, dime = 0, nickel = 0, penny = 0;

    quarter = temp / 0.25;
    dime = (temp - (quarter * 0.25)) / 0.1;
    nickel = (temp - (quarter * 0.25) - (dime * 0.1)) / 0.05;
    penny = (temp - (quarter * 0.25) - (dime * 0.1) - (nickel * 0.05)) / 0.01;

    std::cout << std::format("You need {} {}, {} {}, {} {}, and {} {} to make up ${:.2f}.",
                             quarter, (quarter > 1 ? "quarters" : "quarter"),
                             dime, (dime > 1 ? "dimes" : "dime"),
                             nickel, (nickel > 1 ? "nickles" : "nickel"),
                             penny, (penny > 1 ? "pennies" : "penny"),
                             temp)
              << std::endl;

    return 0;
}