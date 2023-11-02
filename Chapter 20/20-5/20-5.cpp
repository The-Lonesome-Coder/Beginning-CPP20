#include <format>
#include <iostream>
#include <numeric>
#include <vector>


int main()
{
    std::vector<int> vec(20);
    std::iota(vec.begin(), vec.end(), 1);

    double total = std::accumulate(vec.begin(), vec.end(), 0);

    std::cout << std::format("The total of the vector is: {}\nThe average of the vector is: {}",
                              total, total / vec.size())
              << std::endl;
}