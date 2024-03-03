/*
We’re going to write a little game with square numbers (numbers which can be created by multiplying an 
integer with itself (1, 4, 9, 16, 25, …)).

Ask the user to input 2 numbers, the first is the number to start at, the second is the amount of numbers 
to generate. Generate square numbers in the range that was chosen by the user. 
Then generate a random integer from 2 to 4, and multiple each square number by the random number. 
You can assume that the user enters valid numbers.

The user has to calculate which numbers have been generated. The program checks if the user guessed correctly 
and removes the guessed number from the list. If the user guessed wrong, the game is over and the program 
prints the number that was closest to the user’s final guess, but only if the final guess was not off by more than 4.

*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cmath>
#include "Random.h"  //for our random number generator


bool findNumber(std::vector<int>& arr, int my_guess)
{
    auto found { std::find (arr.begin(), arr.end(), my_guess)};

    if ( found == arr.end() )
        return false;

    arr.erase(found);
    return true;
}

int findClosest(std::vector<int>& arr, int my_guess)
{
    const auto closest{std::min_element(arr.begin(), arr.end(),
                                        [&my_guess](const int &a, const int &b) {

                                            return std::abs(a - my_guess) < std::abs(b - my_guess);
                                        })};
    return *closest;
}

int main()
{
    std::cout << "Start where? ";
    int first{};
    std::cin >> first;

    std::cout << "How many? ";
    int length{};
    std::cin >> length;

    std::vector<int> arr(length);
    arr[0] = first;

    //populates array with regular values (i.e 4,5,6,7,8,9,10,11)
    for (size_t i{1}; i < length; i++)
        arr[i] = first + i;


    // creating an array of squares
    for (size_t i{0}; i < length; i++)
        arr[i] *= arr[i];


    std::cout << '\n';
  
    //create a random number from 2 to 4, use Random.h
    int random_num{Random::get(2, 4)};
    std::cout << "I generated 8 square numbers.";
    std::cout << "Do you know what each number is after multiplying it by " << random_num << "?" << '\n';

    // multiply array by our randon number
    for (size_t i{0}; i < length; i++)
        arr[i] *= random_num;

    int count{length};

    while (true)
    {
        int my_guess{}; 
        std::cin >> my_guess;


        // if findNumber() returns false (my_guess is NOT in the array)
        if (!findNumber(arr, my_guess))
        {
            std::cout << my_guess << " is wrong! Try " << findClosest(arr, my_guess) << " next time.";
            break;
        }

        count--;
        if(count == 0)
        {
            std::cout << "Nice! you found all the numbers, good job!\n";
            break;
        }

        std::cout << "Nice! " << count << " number(s) left." << '\n';
    }
  
    return 0;
}
