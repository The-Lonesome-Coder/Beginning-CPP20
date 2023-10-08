module rational;

import <format>;
import <numeric>;
import <stdexcept>;


// Basic constructor
Rational::Rational(const int num, const int denom)
{
    if (denom == 0)
    {
        throw std::overflow_error("The m_denominator cannot be 0");
    }

    m_numerator = num;
    m_denominator = denom;
}


// Copy constructor
Rational::Rational(Rational& num)
{
    m_numerator = num.m_numerator;
    m_denominator = num.m_denominator;
}


Rational& Rational::operator = (Rational& num)
{
    if (this != &num)                                                                               // The sample should have different address
    {
        m_numerator = num.m_numerator;
        m_denominator = num.m_denominator;
    }

    return *this;
}


// Operator overload
Rational& Rational::operator += (Rational& num)
{
    m_numerator = m_numerator * num.m_denominator + num.m_numerator * m_denominator;
    m_denominator *= num.m_denominator;

    simplify(m_numerator, m_denominator);

    return *this;
}


Rational Rational::operator + (Rational& num)
{
    Rational copy {*this};
    copy += num;

    return copy;
}


Rational& Rational::operator -= (Rational& num)
{
    m_numerator = m_numerator * num.m_denominator - num.m_numerator * m_denominator;
    m_denominator *= num.m_denominator;

    simplify(m_numerator, m_denominator);

    return *this;
}


Rational Rational::operator - (Rational& num)
{
    Rational copy {*this};
    copy -= num;

    return copy;
}


Rational& Rational::operator *= (Rational& num)
{
    m_numerator *= num.m_numerator;
    m_denominator *= num.m_denominator;

    simplify(m_numerator, m_denominator);

    return *this;
}


Rational Rational::operator * (Rational& num)
{
    Rational copy {*this};
    copy *= num;

    return copy;
}


Rational& Rational::operator /= (Rational& num)
{
    m_numerator *= num.m_denominator;
    m_denominator *= num.m_numerator;

    simplify(m_numerator, m_denominator);

    return *this;
}


Rational Rational::operator / (Rational& num)
{
    Rational copy {*this};
    copy /= num;

    return copy;
}


std::partial_ordering Rational::operator <=> (const Rational& num) const
{
    return m_numerator * num.m_denominator <=> num.m_numerator * m_denominator;
}


std::partial_ordering Rational::operator <=> (const double num) const
{
    return static_cast<double>(*this) <=> num;
}


bool Rational::operator == (Rational num)
{
    return m_numerator * num.m_denominator == num.m_numerator * m_denominator;
}


bool Rational::operator == (const double value)
{
    return static_cast<double>(*this) == value;
}


std::ostream& operator << (std::ostream& stream, const Rational& num)
{
    stream << std::format("The number represented in decimal: {:.5f}", num.getNumber());

    return stream;
}


long long int Rational::getNumerator() const
{
    return m_numerator;
}


long long int Rational::getDenominator() const
{
    return m_denominator;
}


void Rational::setNumerator(const long long int& num)
{
    m_numerator = num;
}


void Rational::setDenominator(const long long int& num)
{
    m_denominator = num;
}


double Rational::getNumber() const
{
    return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
}


void Rational::simplify(long long int& num, long long int& denom)
{
    long long int divisor = std::gcd(num, denom);

    num /= divisor;
    denom /= divisor;
}