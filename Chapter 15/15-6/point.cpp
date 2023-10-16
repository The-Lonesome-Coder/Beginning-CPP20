module point;


// Constructor
Point::Point(const double xPosition, const double yPosition)
    : m_xPosition { xPosition }, m_yPosition { yPosition } {};


// Getter
double Point::getX() const
{
    return m_xPosition;
}


double Point::getY() const
{
    return m_yPosition;
}


// Setter
void Point::setX(const double& newX)
{
    m_xPosition = newX;
}


void Point::setY(const double& newY)
{
    m_yPosition = newY;
}