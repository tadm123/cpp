/*
You are provided with a vector of N integers. Then, you are given 2 queries. 
For the first query, you are provided with 1 integer, which denotes a position in the vector. 
The value at this position in the vector needs to be erased. The next query consists of 2 integers denoting a range of the positions in the vector. 
The elements which fall under that range should be removed. The second query is performed on the updated vector which we get after performing the first query.
*/  

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


int main() {

    int length;
    std::cin >> length;

    std::vector <int> v(length);

    for (int i{0}; i < length; i++)
    {
        std::cin >> v[i];
    }

    int position;
    std::cin >> position;
    v.erase(v.begin() + position - 1);


    int beginning, ending;
    std::cin >> beginning >> ending;

    v.erase(v.begin() + beginning - 1,v.begin() + ending - 1);

    std::cout << v.size() << '\n';

    for (const auto& elem: v)
    {
        std::cout << elem <<" ";
    }

    return 0;
}
