module lion;


// Constructor
Lion::Lion(std::string_view name, const int& weight)
    : Animal { name, weight } {};


// Copy constructor
Lion::Lion(const Lion& anotherLion)
    : Animal { anotherLion } {};