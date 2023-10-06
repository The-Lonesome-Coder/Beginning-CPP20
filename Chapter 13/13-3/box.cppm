export module box;


import <compare>;
import <ostream>;
import <format>;


export class Box
{
    public:
        Box() = default;
        Box(double length, double width, double height);

        std::partial_ordering operator <=> (const Box &otherBox) const;
        std::partial_ordering operator <=> (const double &otherVolume) const;

        bool operator == (const Box &otherBox) const = default;

        Box& operator += (const Box& aBox);
        Box operator + (const Box& aBox) const;

        Box& operator *= (const double num);
        Box operator * (const double num) const;

        Box& operator /= (const double num);
        Box operator / (const double num) const;


        double volume() const;

        double getLength() const { return m_length; }
        double getWidth() const { return m_width; }
        double getHeight() const { return m_height; }

    private:
        double m_length {1.0};
        double m_width {1.0};
        double m_height {1.0};
};


export std::ostream& operator << (std::ostream& stream, const Box& box);

export Box operator * (double factor, const Box& box);