#include <format>
#include <iostream>
#include <vector>


int main(void)
{
    std::vector<int> product {1001, 1003};
    std::vector<int> quantity {25, 10};
    std::vector<double> price {9.95, 15.5};
    std::vector<double> cost {0};

    int size = product.size();

    for (int i = 0; i < size; ++i)
    {
        cost[i] = quantity[i] * price[i];
    }

    constexpr auto format = "{:^15} | {:^15} | ${:^15} | ${:^15.5}";

    std::cout << std::format(format,
                             "Product",
                             "Quantity",
                             "Unit Price",
                             "Cost")
              << std::endl;

    for (int i = 0; i < size; ++i)
    {
        std::cout << std::format(format,
                                 product[i],
                                 quantity[i],
                                 price[i],
                                 cost[i])
                  << std::endl;
    }

    double total = 0;

    for (int i = 0; i < size; ++i)
    {
        total += cost[i];
    }

    std::cout << std::format("{:^17} {:^17} {:^18} ${:^15}", " ", " ", " ", total)
              << std::endl;

    return 0;
}