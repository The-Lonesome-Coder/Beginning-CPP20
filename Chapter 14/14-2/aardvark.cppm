export module aardvark;

import animal;


export class Aardvark : public virtual Animal
{
    public:
        using Animal::Animal;
        using Animal::who;
};