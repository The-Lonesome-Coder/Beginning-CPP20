module executive;

import <format>;
import <iostream>;


void Executive::who() const
{
    std::cout << std::format("{} is a {} employee.\n", getName(), getGender());
}