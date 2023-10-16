export module shape;

import point;


export class Shape
{
    public:
        // Constructor
        Shape(const Point& position);

        // Destructor
        virtual ~Shape() = default;

        // Calculate the area of the shape - pure
        virtual double area() const = 0;

        // Calculate the perimeter - pure
        virtual double perimeter() const = 0;

        // Scale the shape - pure
        virtual void scale(const double& factor) = 0;

        // Move a shape
        virtual void move(const Point& position);


    private:
        Point m_position;
};