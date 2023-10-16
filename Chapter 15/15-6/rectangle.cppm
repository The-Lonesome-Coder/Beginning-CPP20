export module shape.rectangle;

import shape;


export class Rectangle : public Shape
{
    public:
        using Shape::Shape;

        // Constructor
        Rectangle(const Point& position, const double length, const double width);

        // Destructor
        virtual ~Rectangle() = default;

        // Calculate the area of the shape - override
        virtual double area() const override;

        // Calculate the perimeter - override
        double perimeter() const override;

        // Scale the shape - override
        virtual void scale(const double& factor) override;


    private:
        double m_length;
        double m_width;
};