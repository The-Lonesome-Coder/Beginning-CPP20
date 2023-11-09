#include <concepts>
#include <functional>
#include <iterator>
#include <ranges>
#include <vector>


template <std::forward_iterator Iterator,
          std::sentinel_for<Iterator> Sentinel,
          typename Projection = std::identity,
          std::indirect_strict_weak_order<std::projected<Iterator, Projection>> Comparison = std::ranges::less>
Iterator find_optimum(Iterator begin, Sentinel end, Comparison compare = { }, Projection projection = { })
{
    if (begin == end)
    {
        return begin;
    }

    Iterator optimum { begin };

    for (auto iter { ++begin }; iter != end; ++iter)
    {
        if (std::invoke(compare, std::invoke(projection, *iter), std::invoke(projection, *optimum)))
        {
            optimum = iter;
        }
    }

    return optimum;
}