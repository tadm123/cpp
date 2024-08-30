/*
You are given N integers in sorted order. Also, you are given Q queries. 
In each query, you will be given an integer and you have to tell whether that integer is present in the array. 
If so, you have to tell at which index it is present and if it is not present, you have to tell the index at 
which the smallest integer that is just greater than the given number is present. 
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{

    int n{};
    std::cin >> n;

    std::vector<int> my_vector(n);

    //populating vector
    for(int i{0}; i < n ; i++)
        std::cin >> my_vector[i];

    int q{};
    std::cin >> q;

    std::vector<int> my_queries(q);

    for(int i{0}; i < q ; i++)
    {
        std::cin >> my_queries[i];
    }


    for(int i{0}; i < q; i++)
    {
        auto it_found{std::find(my_vector.begin(), my_vector.end(), my_queries[i])};
        if (it_found != my_vector.end())    // if it found the number
        {
            auto position{std::distance(my_vector.begin(), it_found)};
            std::cout << "Yes " << position + 1 << "\n";
        }
        else                                // if it didn't found it
        {
            auto low {std::lower_bound (my_vector.begin(), my_vector.end(), my_queries[i])};
            std::cout << "No " << (low - my_vector.begin() + 1) << "\n";
        }
    }

    return 0;
}

