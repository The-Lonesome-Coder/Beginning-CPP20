/**
 * The output will be 2
*/
#include <iostream>


int main(void)
{
    // Initialize an unsigned int, value 430, binary 1'1010'1110
    auto k {430u};

    // Right shift k 4 bits, which will result in 1'1010,
    // "and" it with "inverted unsigned int "0" and left shift it 3 bit, then invert back",
    // result in 0111.
    // 1'1010 & 0111 = 0'0010 = 2 (decimal)
    auto j {(k >> 4) & ~(~0u << 3)};

    std::cout << j << std::endl;
}