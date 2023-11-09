#include <forward_list>
#include <iostream>
#include <iterator>


template <std::random_access_iterator Iter>
auto my_advance(Iter iter, std::iter_difference_t<Iter> n)
{
    return iter + n;
}


template <std::bidirectional_iterator Iter>
auto my_advance(Iter iter, std::iter_difference_t<Iter> n)
{
    while (n > 0)
    {
        ++iter;
        --n;
    }

    while (n < 0)
    {
        --iter;
        ++n;
    }

    return iter;
}


template <std::input_or_output_iterator Iter>
auto my_advance(Iter iter, std::iter_difference_t<Iter> n)
{
    while (n > 0)
    {
        ++iter; --n;
    }

    return iter;
}