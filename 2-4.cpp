#include <cmath>
#include <format>
#include <iostream>


// BMI Formula
double bmi(double weight, double height)
{
    return weight / std::pow((height / 100), 2.0);
}


int main(void)
{
    double weight = 0.0, height = 0.0;

    std::cout << "Please enter weight and height:\n";
    std::cin >> weight >> height;

    double result = bmi(weight, height);

    std::cout << std::format("Your BMI is {:.2f}", result) << std::endl;

    return 0;
}