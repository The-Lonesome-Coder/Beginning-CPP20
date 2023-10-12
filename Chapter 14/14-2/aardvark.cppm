export module aardvark;

import <string_view>;

import animal;


export class Aardvark : public virtual Animal
{
    public:
        using Animal::Animal;
        using Animal::who;
};