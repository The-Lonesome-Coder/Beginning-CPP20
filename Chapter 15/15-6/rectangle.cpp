module shape.rectangle;


// Constructor
Rectangle::Rectangle(const Point& position, const double length, const double width)
    : Shape { position }, m_length { length }, m_width { width } {};


// Calculate the area of the shape - override
double Rectangle::area() const
{
    return m_length * m_width;
}


// Calculate the perimeter - override
double Rectangle::perimeter() const
{
    return 2 * (m_length + m_width);
}


// Scale the shape - override
void Rectangle::scale(const double& factor)
{
    m_length *= factor;
    m_width *= factor;
}