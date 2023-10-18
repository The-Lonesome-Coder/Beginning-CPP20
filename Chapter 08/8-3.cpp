#include <iostream>


int main(int argc, char *argv[])
{
    if (argc > 5 || argc < 3)
    {
        std::cout << "Please enter two to 5 command-line arguments."
                  << std::endl;

        return 1;
    }

    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << std::endl;
    }

    return 0;
}