export module linkedList;

import <utility>;


export template <typename T>
class LinkedList
{
    public:
        LinkedList() = default;                                         // Default constructor
        LinkedList(const LinkedList& anotherList);                      // Copy constructor

        ~LinkedList();                                                  // Destructor

        LinkedList& operator = (const LinkedList& anotherList);         // Copy Assignment

        void push_front(const T& value);                                // Add value to the head
        void push_back(const T& value);                                 // Add value to the tail

        void pop_front();                                               // Remove the first value
        void pop_back();                                                // Remove the last value

        T& front();                                                     // Get the value at the head
        const T& front() const;                                         // Get the value at the head
        T& back();                                                      // Get the value at the tail
        const T& back() const;                                          // Get the value at the tail

        bool empty() const;                                             // Check whether the list is empty or not

        void clear();                                                   // Remove all elements in the list

        size_t getSize() const;                                         // Get the size of the list

        void swap(const LinkedList& anotherList) noexcept;              // swap()

        class Iterator;
        Iterator front_iterator() const;                                // Iterator starts at the head
        Iterator back_iterator() const;                                 // Iterator starts at the tail


    private:
        class Node
        {
            public:
                Node(const T& value)
                    : m_value { value }, m_next {}, m_previous {} {};

                T m_value;
                Node* m_next;
                Node* m_previous;
        };

        Node* m_head;
        Node* m_tail;
        size_t m_size;
};


// Non-member swap()
template <typename T>
void swap(const LinkedList<T>& oneList, const LinkedList<T>& anotherList)
{
    oneList.swap(anotherList);
}


// Copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList& anotherList)
{
    for (auto iterator { anotherList.front_iterator() }; iterator; iterator.next())
    {
        push_back(iterator.value());
    }
}


// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}


// Assignment operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList& anotherList)
{
    swap(*this, anotherList);

    return *this;
}


// Add value to the head
template <typename T>
void LinkedList<T>::push_front(const T& value)
{
    Node* oldHead { m_head };
    m_head = new Node { value };
    ++m_size;

    if (oldHead)
    {
        oldHead->m_previous = m_head;
        m_head->m_next = oldHead;
    }
    else
    {
        m_tail = m_head;
    }
}


// Add value to the tail
template <typename T>
void LinkedList<T>::push_back(const T& value)
{
    Node* oldTail { m_tail };
    m_tail = new Node { value };
    ++m_size;

    if (oldTail)
    {
        oldTail->m_next = m_tail;
        m_tail->m_previous = oldTail;
    }
    else
    {
        m_head = m_tail;
    }
}


// Template for member functions that remove an object from the head of the list
template<typename T>
void LinkedList<T>::pop_front()
{
    Node* oldHead { m_head };
    if (oldHead == m_tail)
    {
        m_head = m_tail = nullptr;
    }
    else
    {
        m_head = oldHead->m_next;
        m_head->m_previous = nullptr;
    }

    --m_size;
    delete oldHead;
}

// Template function member to remove an object from the tail of the list
template<typename T>
void LinkedList<T>::pop_back()
{
    Node* oldTail { m_tail };
    if (oldTail == m_head)
    {
        m_head = m_tail = nullptr;
    }
    else
    {
        m_tail = oldTail->m_previous;
        m_tail->next = nullptr;
    }

    --m_size;
    delete oldTail;
}


// Template function members to get the object at the head of the list
template<typename T>
T& LinkedList<T>::front()
{
    return m_head->value;
}


template<typename T>
const T& LinkedList<T>::front() const
{
    return m_head->value;
}


// Template function members to get the object at the tail of the list
template<typename T>
T& LinkedList<T>::back()
{
    return m_tail->value;
}


template<typename T>
const T& LinkedList<T>::back() const
{
    return m_tail->value;
}


// Check whether list is empty or not
template<typename T>
bool LinkedList<T>::empty() const
{
    return m_size == 0;
}


// Template to get the size of a list
template<typename T>
size_t LinkedList<T>::getSize() const
{
    return m_size;
}


// Template to clear a list
template<typename T>
void LinkedList<T>::clear()
{
    // Use existing functions (avoid code duplication!)
    while (!empty()) pop_front();
}


// Member swap()
template <typename T>
void LinkedList<T>::swap(const LinkedList& anotherList) noexcept
{
    std::swap(m_head, anotherList.m_head);
    std::swap(m_tail, anotherList.m_tail);
    std::swap(m_size, anotherList.m_size);
}


// Nested iterator class
template <typename T>
class LinkedList<T>::Iterator
{
    public:
        explicit Iterator(Node* node);

        const T& value() const;

        bool hasValue() const;
        operator bool() const;

        void next();
        void previous();


    private:
        Node* m_current;
};


// Iterator starts at the head
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::front_iterator() const
{
    return Iterator { m_head };
}


// Iterator starts at the end
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::back_iterator() const
{
    return Iterator { m_tail };
}


// Iterator class constructor
template <typename T>
LinkedList<T>::Iterator::Iterator(Node* node)
    : m_current { node } {}


template <typename T>
const T& LinkedList<T>::Iterator::value() const
{
    return m_current->m_value;
}


// Check value exist
template <typename T>
bool LinkedList<T>::Iterator::hasValue() const
{
    return m_current != nullptr;
}


// bool() operator overload
template <typename T>
LinkedList<T>::Iterator::operator bool() const
{
    return m_current != nullptr;
}


// Move to next element
template<typename T>
void LinkedList<T>::Iterator::next()
{
    m_current = m_current->m_next;
}


// Move to the previous element
template <typename T>
void LinkedList<T>::Iterator::previous()
{
    m_current = m_current->m_previous;
}