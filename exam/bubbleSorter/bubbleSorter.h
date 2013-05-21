#ifndef BUBBLESORTER_H
#define BUBBLESORTER_H

/**
 * @file bubbleSorter.h
 *
 * Implementation of the template BubbleSorter class.
 */

template<typename T>
/// @class BubbleSorter contained all to sort your array. Contained method sort and swap.
class BubbleSorter
{
public:
    template<typename N>
    /// Takes an array, the size and the predicate function.
    void sort(T array[], const int &size, N &comp);

private:
    void swap(T &a, T&b)
    {
        T c = a;
        a = b;
        b = c;
    }
};

template<typename T>
template<typename N>
void BubbleSorter<T>::sort(T array[], const int &size, N &comp)
{
    bool isSorted = false;
    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i < size - 1; i++)
            if (comp(array[i], array[i + 1]))
            {
                swap(array[i], array[i + 1]);
                isSorted = false;
            }
    }
}

#endif // BUBBLESORTER_H
