export module sparseArray;

import <stdexcept>;
import <utility>;
import <vector>;


export template <typename T>
class SparseArray
{
    public:
        T& operator [] (const size_t& index);
        T& at(const size_t& index);
        const T& at(const size_t& index) const;
        bool elementExistAt(const size_t& index) const;


    private:
        T* find(const size_t& index);
        const T* find(const size_t& index) const;

        std::vector<std::pair<size_t, T>> m_elements;
};


// Subscript operator
template <typename T>
T& SparseArray<T>::operator [] (const size_t& index)
{
    if (auto* found { find(index) }; found)
    {
        return *found;
    }
    else
    {
        m_elements.push_back({ index, T{} });

        return *find(index);
    }
}


template <typename T>
T& SparseArray<T>::at(const size_t& index)
{
    return const_cast<T&>(std::as_const(*this).at(index));
}


template <typename T>
const T& SparseArray<T>::at(const size_t& index) const
{
    if (const auto* found { find(index) }; found)
    {
        return *found;
    }
    else
    {
        throw std::out_of_range { "No value exist at given index." };
    }
}


template <typename T>
bool SparseArray<T>::elementExistAt(const size_t& index) const
{
    return find(index) != nullptr;
}


// Helper function
template <typename T>
T* SparseArray<T>::find(const size_t& index)
{
    return const_cast<T*>(std::as_const(*this).find(index));
}


// Helper function - const version
template <typename T>
const T* SparseArray<T>::find(const size_t& index) const
{
    for (auto& element : m_elements)
    {
        if (std::get<0>(element) == index)
        {
            return &std::get<1>(element);
        }
    }

    return nullptr;
}