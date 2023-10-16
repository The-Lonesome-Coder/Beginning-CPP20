module shape;


// Constructor
Shape::Shape(const Point& position)
    : m_position { position } {};


// Move a shape
void Shape::move(const Point& position)
{
    m_position = position;
}