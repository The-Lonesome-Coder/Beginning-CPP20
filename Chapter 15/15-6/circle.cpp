module shape.circle;

import <cmath>;
import <numbers>;



// Constructor
Circle::Circle(const Point& center, const double radius)
    : Shape { center }, m_radius { radius } {};


// Calculate the area of the shape - override
double Circle::area() const
{
    return std::pow(m_radius, 2) * std::numbers::pi;
}


// Calculate the perimeter - override
double Circle::perimeter() const
{
    return 2 * std::numbers::pi * m_radius;
}


// Scale the shape - override
void Circle::scale(const double& factor)
{
    m_radius *= factor;
}