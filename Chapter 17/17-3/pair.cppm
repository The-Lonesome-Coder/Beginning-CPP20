export module pair;

import <compare>;
import <format>;
import <ostream>;


export template <typename T1, typename T2>
class Pair
{
    public:
       Pair(const T1 first, const T2 second);                                       // Constructor
       ~Pair() = default;                                                           // Destructor

       std::partial_ordering operator <=> (const Pair& anotherPair) const;          // Three-way comparison

       bool operator == (const Pair& anotherPair) const;                            // Equality comparison

       // Public members
       T1 m_first;
       T2 m_second;
};


// Constructor
template <typename T1, typename T2>
Pair<T1, T2>::Pair(const T1 first, const T2 second)
    : m_first { first }, m_second { second } {}


// Three-way comparison operator
template <typename T1, typename T2>
std::partial_ordering Pair<T1, T2>::operator <=> (const Pair& anotherPair) const
{
    if (m_first == anotherPair.m_first)
    {
        return m_second <=> anotherPair.m_second;
    }

    return m_first <=> anotherPair.m_first;
}


// Equality comparison
template <typename T1, typename T2>
bool Pair<T1, T2>::operator == (const Pair& anotherPair) const
{
    return (m_first == anotherPair.m_first) && (m_second == anotherPair.m_second);
}


// Output operator
export template <typename T1, typename T2>
std::ostream& operator << (std::ostream& stream, const Pair<T1, T2>& aPair)
{
    return stream << std::format("The first element of the pair: {}\nThe second element of the pair: {}\n",
                                  aPair.m_first, aPair.m_second);
}