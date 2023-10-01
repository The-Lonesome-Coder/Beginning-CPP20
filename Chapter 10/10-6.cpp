#include <algorithm>
#include <iostream>


template <typename T>
int Partition(T* array, int start, int end)
{
    int pivot = end, j = start;

    for (int i = start; i < end; ++i)
    {
        if (array[i] < array[pivot])
        {
            std::swap(array[i], array[j]);

            ++j;
        }
    }

    std::swap(array[j], array[pivot]);

    return j;
}


template <typename T>
void Quicksort(T* array, int start, int end)
{
    if (start < end)
    {
        int p = Partition(array, start, end);

        Quicksort(array, start, p - 1);
        Quicksort(array, p + 1, end);
    }
}


template <typename T>
void PrintArray(T* array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << ' ';
    }

    std::cout << std::endl;
}


int main()
{

    int array[] = { 1 , 10 , 11 , 9 , 14 , 3 , 2 , 20 , 19, 43, 57, 3, 2 };

    int n = sizeof(array)/sizeof(int);

    Quicksort(array, 0, n - 1);

    PrintArray(array, n);

    return 0;
}