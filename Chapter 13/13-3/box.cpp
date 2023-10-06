module box;

import <algorithm>;
import <iostream>;
import <format>;


Box::Box(double length, double width, double height)
    :m_length {length}, m_width {width}, m_height {height}
{ }


double Box::volume() const
{
    return m_length * m_width * m_height;
}


std::partial_ordering Box::operator <=> (const Box& otherBox) const
{
    return volume() <=> otherBox.volume();
}


std::partial_ordering Box::operator <=> (const double& otherVolume) const
{
    return volume() <=> otherVolume;
}


Box& Box::operator += (const Box& aBox)
{
    m_length = std::max(m_length, aBox.m_length);
    m_width = std::max(m_width, aBox.m_width);
    m_height += aBox.m_height;

    return *this;

}


Box Box::operator + (const Box& aBox) const
{
    Box copy {*this};

    copy += aBox;

    return copy;
}


Box& Box::operator *= (const double num)
{
    m_height *= num;

    return *this;
}


Box Box::operator * (const double num) const
{
    Box copy {*this};

    copy *= num;

    return copy;
}


Box operator * (double factor, const Box& box)
{
    return box * factor;
}


Box& Box::operator /= (const double num)
{
    m_height /= num;

    return *this;
}


Box Box::operator / (const double num) const
{
    Box copy(*this);

    copy /= num;

    return copy;
}


std::ostream& operator << (std::ostream& stream, const Box& box)
{
    stream << std::format("Box({:.1f}, {:.1f}, {:.1f})",
                          box.getLength(), box.getWidth(), box.getHeight());

    return stream;
}