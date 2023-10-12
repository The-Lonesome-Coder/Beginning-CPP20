export module lion;

import <string_view>;
import animal;


export class Lion : public virtual Animal
{
    public:
        using Animal::Animal;
        using Animal::who;
};