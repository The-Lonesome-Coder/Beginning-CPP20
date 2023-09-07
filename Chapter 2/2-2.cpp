#include <cmath>   // std::pow()
#include <format>
#include <iostream>
#include <numbers>   // std::numbers::pi


// Function for calculating the area of circle
double circle_area(double radius)
{
    return std::pow(radius, 2.0) * std::numbers::pi;
}


int main(void)
{
    double radius = 0.0, area = 0.0;

    std::cout << "Enter radius: " << std::endl;
    std::cin >> radius;

    area = circle_area(radius);

    std::cout << std::format("The area of a circle with radius {:.2f} is {:.5f}", radius, area)
              << std::endl;

    return 0;
}