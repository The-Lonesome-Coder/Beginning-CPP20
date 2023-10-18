#include <cmath>
#include <format>
#include <iostream>


// Formula given
double tree_height(double distance, double height, double radian)
{
    return height + distance * std::tan(radian);
}


int main(void)
{
    // Constant
    const double inches_foot = 12.0, pi_degree = 180.0;

    double d_feet = 0.0, d_inches = 0.0, h= 0.0, angle = 0.0, tree_h = 0.0;

    // Distance from tree - convert to feet
    std::cout << "Please enter your distance from a tree: (in feet and inches)\n";
    std::cin >> d_feet >> d_inches;

    double distance = d_feet + (d_inches / inches_foot);


    // Height of eye - convert to feer
    std::cout << "Please enter the height of your eye: (in inches)\n";
    std::cin >> h;

    double height = h / inches_foot;


    // Angle - convert to radian
    std::cout << "Please enter the angle: (in degree)" << std::endl;
    std::cin >> angle;

    double radian = angle * (std::numbers::pi / pi_degree);


    // Result
    tree_h = tree_height(distance, height, radian);

    std::cout << std::format("The height of the tree is {:.5f} inches.", tree_h);

    return 0;
}