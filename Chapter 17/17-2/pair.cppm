export module pair;

import <compare>;


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