module integer;


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


int Integer::compare(const Integer &i) const
{
    if (m_number < i.m_number)
    { return -1; }

    if (m_number == i.m_number)
    { return 0; }

    return 1;
}


Integer &Integer::add(const Integer &i)
{
    m_number += i.m_number;

    return *this;
}


Integer &Integer::subtract(const Integer &i)
{
    m_number -= i.m_number;

    return *this;
}


Integer &Integer::multiply(const Integer &i)
{
    m_number *= i.m_number;

    return *this;
}