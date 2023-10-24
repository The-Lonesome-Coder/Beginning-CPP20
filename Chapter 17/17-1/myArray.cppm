export module myArray;

import <initializer_list>;
import <stdexcept>;
import <utility>;


export template <typename T>
class MyArray
{
    public:

        MyArray();                                          // Default constructor
        MyArray(size_t size);                               // Constructor
        MyArray(std::initializer_list<T> elements);      // List initializer constructor
        MyArray(const MyArray& another);                    // Copy constructor

        ~MyArray();                                         // Destructor

        MyArray& operator = (const MyArray& another);       // Copy assignment

        T& operator [] (size_t index);                      // Subscript operator
        const T& operator [] (size_t index) const;          // Subscript operator on const-array

        size_t getSize() const;                             // Getter

        void swap(MyArray& other) noexcept;                 // For copy-and-swap idiom
        void push_back(const T& newElement);                // Add new element to the array


    private:
        T* m_elements;
        size_t m_size;
};


// Default constructor
template <typename T>
MyArray<T>::MyArray()
    : MyArray { 0 } {}


// Constructor
template <typename T>
MyArray<T>::MyArray(size_t size)
    : m_elements { new T[size] {} }, m_size { size } {}


// List initializer constructor
template <typename T>
MyArray<T>::MyArray(std::initializer_list<T> elements)
    : m_elements { new T[elements.size()] }, m_size { elements.size() }
{
    for (size_t i { 0 }; const T & element : elements)
    {
        m_elements[i] = element;
        ++i;
    }
}


// Copy constructor
template <typename T>
MyArray<T>::MyArray(const MyArray& another)
    : MyArray { another.m_size }
{
    for (size_t i { 0 }; i < m_size; ++i)
    {
        m_elements[i] = another.m_elements[i];
    }
}


// Destructor
template <typename T>
MyArray<T>::~MyArray()
{
    delete[] m_elements;
}


// Copy assignment
template <typename T>
MyArray<T>& MyArray<T>::operator = (const MyArray& another)
{
    MyArray<T> copy { another };
    swap(copy);

    return *this;
}


// Subscript operator
template <typename T>
T& MyArray<T>::operator [] (size_t index)
{
    return const_cast<T&>(std::as_const(*this)[index]);
}


// Subscript operator on const-array
template <typename T>
const T& MyArray<T>::operator [] (size_t index) const
{
    if (index >= m_size)
    {
        throw std::out_of_range { "Index too large." };
    }

    return m_elements[index];
}


// Getter
template <typename T>
size_t MyArray<T>::getSize() const
{
    return m_size;
}


// For copy-and-swap idiom
template <typename T>
void MyArray<T>::swap(MyArray& other) noexcept
{
    std::swap(m_elements, other.m_elements);
    std::swap(m_size, other.m_size);
}


// Add new element to the array
template <typename T>
void MyArray<T>::push_back(const T& newElement)
{
    MyArray<T> copy(m_size + 1);

    for (size_t i { 0 }; i < m_size; ++i)
    {
        copy[i] = m_elements[i];
    }

    copy[m_size] = newElement;

    swap(copy);
}


// Public access swap
export template <typename T>
void swap(MyArray<T>& one, MyArray<T>& other) noexcept
{
    one.swap(other);
}