export module rational;

import <compare>;
import <iostream>;
import <ostream>;


export class Rational
{
    public:

        Rational(const int num, const int denom);                                                   // Basic constructor
        Rational(Rational& num);                                                                    // Copy constructor
        ~Rational() = default;                                                                      // Destructor

        Rational& operator = (Rational& num);                                                       // Copy assignment

        Rational& operator += (Rational& num);                                                      // Overload operator
        Rational operator + (Rational& num);

        Rational& operator -= (Rational& num);
        Rational operator - (Rational& num);

        Rational& operator *= (Rational& num);
        Rational operator * (Rational& num);

        Rational& operator /= (Rational& num);
        Rational operator / (Rational& num);

        std::partial_ordering operator <=> (const Rational& num) const;                                   // Comparison
        std::partial_ordering operator <=> (const double num) const;
        bool operator == (const Rational num);
        bool operator == (const double num);
        explicit operator bool() const { return m_numerator != 0; }

        explicit operator double() const { return static_cast<double>(m_numerator) / m_denominator; }   // Type conversion
        explicit operator float() const { return static_cast<float>(m_numerator) / m_denominator; }

        long long int getNumerator() const;                                                         // Private member access function
        long long int getDenominator() const;
        double getNumber() const;

        void setNumerator(const long long int& num);
        void setDenominator(const long long int& num);

        void simplify(long long int& num, long long int& denom);                                    // Simplify the fraction

    private:
        long long int m_numerator;
        long long int m_denominator;
};


export std::ostream& operator << (std::ostream& stream, const Rational& num);