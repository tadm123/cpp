/*
Consider an n-element array, a, where each index  in the array contains a reference to an array of ki 
integers (where the value of ki varies from array to array). See the Explanation section below for a diagram.

Given a, you must answer q queries. Each query is in the format i j, where i denotes an index in array a and j 
denotes an index in the array located at a[i]. 
For each query, find and print the value of element j in the array at location a[i] on a new line.

For each pair of i and j values (i.e., for each query), print a single integer that denotes the element located 
at index j of the array referenced by a[i]. There should be a total of q lines of output.
*/


#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

int main() {

    int n{}; // number of variable length arrays 
    int q{}; // number of queries 

    std::cin >> n >> q;

    std::vector<std::vector<int>> outerVector(n); // initialize an array "outerVector" containing variable length arrays

  
    for (int i{0}; i < n; i++)
    {
        int innerSize{0};
        std::cin >> innerSize;   //input size of inner variable size vector

        outerVector[i].resize(innerSize);  //resizing element [0] of outer array with your input (i.e 3)

        for (int j{0}; j < innerSize; j++)
        {
            std::cin >> outerVector[i][j];      // 5 10 2
        }
    }

    
    std::vector<std::vector<int>> queries{0};    // Note that queries columns always going to be of size 2 (i.e [i][2])

    // get queries from user and store them in a queries array
    for (int i{0}; i < q; i++)
    {
        int index_outer{}; //index of outer vector
        int index_inner{};  //index of inner variable sizes vector
        std::cin >> index_outer >> index_inner;
        std::vector<int> myarr{index_outer,index_inner};
        queries.push_back(myarr);
    }

    // print the values that user queried
    for (int i{0}; i < q ; i++)
    {
        int index_outer = queries[i][0];  //1st iteration: queries[0][0] = 0, 2nd iteration: queries[0][1] = 1
        int index_inner = queries[i][1];
        std::cout << outerVector[index_outer][index_inner] << '\n';
    }

  
    /* 
    print arrays check
    std::cout << "Arrays:" << '\n';
    for (int i{0}; i < n; i++)
    {
        std::size_t innerSize{outerVector[i].size()};
        for (std::size_t j{0}; j < innerSize; j++)
        {
            std::cout << outerVector[i][j] << " ";
        }
        std:: cout << '\n';
    }
    */

    return 0;
}
