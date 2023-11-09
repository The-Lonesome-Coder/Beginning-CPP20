// Asserting that a type models a concept
#include <concepts>
#include <ranges>
#include <type_traits>
#include <list>
#include <vector>
#include <string>

template <typename Iter>
concept BidirectionalIterator = true; // Feel free to further work out all requirements...

template<class Iter>
concept RandomAccessIterator = BidirectionalIterator<Iter>
  && requires(const Iter i, const Iter j, Iter k, const int n)
     {
        { i - n };
            requires std::same_as<decltype(i - n), Iter>;

        { i + n };
            requires std::same_as<decltype(i + n), Iter>;

        { n + i };
            requires std::same_as<decltype(n + i), Iter>;

        i[n];
            requires std::same_as<decltype(i[n]), decltype(*i)>;

        i < j;
        i > j;
        i <= j;
        i >= j;
            requires std::convertible_to<decltype(i < j), bool>
                     && std::convertible_to<decltype(i > j), bool>
                     && std::convertible_to<decltype(i <= j), bool>
                     && std::convertible_to<decltype(i >= j), bool>;
     };


template <typename T>
concept NoExceptDestructible = requires (T & value) { { value.~T() } noexcept; };


template <typename C>
concept Character = std::same_as<std::remove_cv_t<C>, char>
                    || std::same_as<std::remove_cv_t<C>, char8_t>
                    || std::same_as<std::remove_cv_t<C>, char16_t>
                    || std::same_as<std::remove_cv_t<C>, char32_t>
                    || std::same_as<std::remove_cv_t<C>, wchar_t>;


template <typename S>
concept String = std::ranges::range<S> && requires(S & s, const S & cs)
{
    typename S::value_type;
    requires Character<typename S::value_type>;
    { cs.length() } -> std::integral;
    { s[0] } -> std::same_as<typename S::value_type&>;
    { cs[0] } -> std::convertible_to<typename S::value_type>;
    { s.data() } -> std::same_as<typename S::value_type*>;
    { cs.data() } -> std::same_as<const typename S::value_type*>;
};


static_assert(NoExceptDestructible<std::string>);
static_assert(NoExceptDestructible<int>);
static_assert(String<std::string>);
static_assert(!String<std::vector<char>>);
static_assert(Character<char>);
static_assert(Character<const char>);
static_assert(RandomAccessIterator<std::vector<int>::iterator>);
static_assert(!RandomAccessIterator<std::list<int>::iterator>);
static_assert(RandomAccessIterator<int*>);

int main()
{

}