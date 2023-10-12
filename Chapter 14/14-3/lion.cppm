export module lion;

import animal;


export class Lion : public virtual Animal
{
    public:
        using Animal::Animal;

        void who() const;
};