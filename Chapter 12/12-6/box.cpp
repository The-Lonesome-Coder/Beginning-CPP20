module box;

import <iostream>;
import <format>;


double Box::volume() const
{
    return m_length * m_width * m_height;
}


int Box::compare(const Box &box) const
{
    if (volume() < box.volume())
    { return -1; }

    if (volume() == box.volume())
    { return 0; }

    return +1;
}


void Box::listBox() const
{
    std::cout << std::format("Box({:.1f},{:.1f},{:.1f})", m_length, m_width, m_height);
}