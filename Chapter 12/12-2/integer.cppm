export module integer;

import <iostream>;


export class Integer
{
    public:
        // Default constructor
        Integer() = default;

        // Constructor
        Integer(int num) : m_number {num}
        { std::cout << "Constructor 1 called.\n"; };

        // Copy constructor
        Integer(const Integer &i);

        int getValue() const;
        void setValue(const int num);
        void showValue() const;
        int compare(const Integer &i);

    private:
        int m_number = 0;
};


Integer::Integer(const Integer &i)
    : m_number {i.m_number}
{
    std::cout << "Copy constructor called.\n";
}