export module sparseArray;


import <memory>;
import <stdexcept>;
import <string>;
import <utility>;
import <vector>;


export template<typename T>
class SparseArray
{
    public:
        T& operator[](size_t index);
        T& at(size_t index);
        const T& at(size_t index) const;
        bool element_exists_at(size_t index) const;

    private:
        T* find(size_t index);
        const T* find(size_t index) const;

        std::vector<std::pair<size_t, T>> m_values;
};


template<typename T>
T& SparseArray<T>::operator[](size_t index)
{
    if (auto* found { find(index) }; found)
    {
        return *found;
    }
    else
    {
        m_values.push_back({ index, T{} });
        return m_values.back().second;
    }
}


template<typename T>
const T& SparseArray<T>::at(size_t index) const
{
    const auto* found { find(index) };
    if (found)
    {
        return *found;
    }
    else
    {
        throw std::out_of_range { "No value exists at index " + std::to_string(index) };
    }
}


template<typename T>
T& SparseArray<T>::at(size_t index)
{
    return const_cast<T&>(std::as_const(*this).at(index));
}


template<typename T>
bool SparseArray<T>::element_exists_at(size_t index) const
{
    return find(index) != nullptr;
}


template<typename T>
const T* SparseArray<T>::find(size_t index) const
{
    for (auto& pair : m_values)
    {
        if (pair.first == index)
            return &pair.second;
    }
    return nullptr;
}


template<typename T>
T* SparseArray<T>::find(size_t index)
{
    return const_cast<T*>(std::as_const(*this).find(index));
}