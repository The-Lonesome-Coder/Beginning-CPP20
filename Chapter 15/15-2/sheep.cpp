module animal.sheep;

import <format>;


std::string Sheep::who() const
{
    return std::format("My name is: Woolly {}.\nI weight: {:.2f}", getName(), getWeight() * 0.9);
}


std::string_view Sheep::sound() const
{
    return "Baa~~~";
}