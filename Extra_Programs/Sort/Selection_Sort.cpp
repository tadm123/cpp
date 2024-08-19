/* 
Selection is one of the easiest sorthing algorithims, it performs the following steps to sort an array from smallest to largest:

1. Starting at array index 0, search the entire array to find the smallest value
2. Swap the smallest value found in the array with the value at index 0
3. Repeat steps 1 & 2 starting from the next index
*/

#include <iostream>
#include <iterator>
#include <utility>

int main()
{
    int array[]{ 30, 50, 20, 10, 40 };
    constexpr int length{ static_cast<int>(std::size(array)) };

    // Step through each element of the array
    // (except the last one, which will already be sorted by the time we get there)
    for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
    {
        // smallestIndex is the index of the smallest element we’ve encountered this iteration
        // Start by assuming the smallest element is the first element of this iteration
        int smallestIndex{ startIndex };

        // Then look for a smaller element in the rest of the array
        for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
        {
            // If we've found an element that is smaller than our previously found smallest
            if (array[currentIndex] < array[smallestIndex])
                // then keep track of it
                smallestIndex = currentIndex;
        }

        // smallestIndex is now the index of the smallest element in the remaining array
        // swap our start element with our smallest element (this sorts it into the correct place)
        std::swap( array[startIndex], array[smallestIndex] );

    }

    // Now that the whole array is sorted, print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

    return 0;
}
