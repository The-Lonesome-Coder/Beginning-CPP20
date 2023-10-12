module aardvark;


Aardvark::Aardvark(std::string_view name, const int& weight)
    : Animal { name, weight } {};


Aardvark::Aardvark(const Aardvark& anotherAardvark)
    : Animal { anotherAardvark } {};