export module integer;

import <iostream>;


export class Integer
{
    public:
        // Constructor
        Integer(const int num = 0);

        // Copy constructor
        Integer(const Integer &i);

        // Destructor
        ~Integer();

        int getValue() const;
        void setValue(const int num);

        void showValue() const;

        int compare(const Integer &i);

        static void printCount();

    private:
        int m_number;
        static inline unsigned int s_count;

};


Integer::Integer(const int num)
    : m_number {num}
{
    ++s_count;
}


Integer::Integer(const Integer &i)
    : m_number {i.m_number}
{
    std::cout << "Copy constructor called.\n";
    ++s_count;
}


Integer::~Integer()
{
    std::cout << "Destructor called.\n";
    --s_count;
}