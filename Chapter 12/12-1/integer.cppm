export module integer;

import <iostream>;


export class Integer
{
    public:
        // Default constructor
        Integer() = default;

        // Constructor
        Integer(int num) : number {num}
        { std::cout << "Constructor 1 called.\n"; };

        int getValue() const;
        void setValue(const int num);
        void showValue() const;

    private:
        int number;
};