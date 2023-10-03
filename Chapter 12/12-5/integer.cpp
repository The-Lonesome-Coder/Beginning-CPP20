module integer;

import <format>;
import <string>;


int Integer::getValue() const
{
    return m_number;
}


void Integer::setValue(const int num)
{
    m_number = num;
}


void Integer::showValue() const
{
    std::cout << "The value is: " << m_number << "." << std::endl;
}


int Integer::compare(const Integer &i)
{
    if (m_number < i.m_number)
    { return -1; }

    if (m_number == i.m_number)
    { return 0; }

    return 1;
}


void Integer::printCount()
{
    std::cout << std::format("There are {} object(s) now.", s_count) << std::endl;
}