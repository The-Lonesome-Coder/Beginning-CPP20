module aardvark;


Aardvark::Aardvark(std::string_view name, const int& weight)
    : Animal { name, weight } {};


void Aardvark::who() const
{
    return Animal::who();
}