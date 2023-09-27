#include <array>
#include <iostream>
#include <vector>

template <typename T, size_t N>
size_t my_size(const T (&array)[N])
{
    return N;
}


template <typename T>
    concept sizable = requires (const T type) { type.size(); };


template <typename T>
    requires sizable<T>
size_t my_size(const T &data)
{
    return data.size();
}


int main(void)
{
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::array<float, 10> ar = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10};

    std::cout << my_size(arr) << std::endl;
    std::cout << my_size(vec) << std::endl;
    std::cout << my_size(ar) << std::endl;
}