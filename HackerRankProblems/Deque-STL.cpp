/*
First line of input will contain the number of test cases T. 
For each test case, you will be given the size of array N and the size of subarray to be used K. 
This will be followed by the elements of the array Ai.
*/

#include <iostream>
#include <deque>

void printKMax(int arr[], int n, int k) 
{
    std::deque <int> myDeque {};
    
    int max{0};
    for (int i{0}; i < n - k + 1; i++)      //5 - 2
    {
        max = arr[i];                //initialize with 1st element

        for (int j{i}; j < i + k; j++)  //i = 3,
        {
            if (max < arr[j])
                max = arr[j];
        }
        //add element (the max) to deque
        myDeque.push_back(max);
    }


    //print deque (contains max elements)
    for (const auto &a: myDeque)
    {
        std::cout << a << " ";
    }

}

int main(){
    int t;
    std::cin >> t;
    while(t>0) {
        int n,k;
        std::cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
            std::cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
