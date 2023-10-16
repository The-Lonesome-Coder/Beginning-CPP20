export module shape.circle;

import shape;


export class Circle : public Shape
{
    public:
        using Shape::Shape;

        // Constructor
        Circle(const Point& center, const double radius);

        // Destructor
        virtual ~Circle() = default;

        // Calculate the area of the shape - override
        virtual double area() const override;

        // Calculate the perimeter - override
        double perimeter() const override;

        // Scale the shape - override
        virtual void scale(const double& factor) override;

        //


    private:
        double m_radius;
};