export module genericSort;

import <utility>;
import <vector>;


template <typename T, typename Comparison>
void sort(std::vector<T>& elements, Comparison compare, size_t start, size_t end);


export template <typename T, typename Comparison>
void genericSort(std::vector<T>& elements, Comparison compare)
{
    if (!elements.empty())
    {
        sort(elements, compare, 0, elements.size() - 1);
    }
}


template <typename T>
void swap(std::vector<T>& elements, size_t first, size_t second)
{
    std::swap(elements[first], elements[second]);
}


// Merge sort
template <typename T, typename Comparison>
void sort(std::vector<T>& elements, Comparison compare, size_t start, size_t end)
{
    if (!(start < end))
    {
        return;
    }

    swap(elements, start, (start + end) / 2);

    size_t current { start };

    for (size_t i { start + 1 }; i <= end; ++i)
    {
        if (compare(elements[i], elements[start]))
        {
            swap(elements, current, i);
            ++current;
        }
    }

    swap(elements, start, current);

    if (current > start)
    {
        sort(elements, compare, start, current - 1);
    }

    if (end > current)
    {
        sort(elements, compare, current + 1, end);
    }
}