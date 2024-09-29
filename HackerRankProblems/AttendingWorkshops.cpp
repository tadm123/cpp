/*
Attending Workshops
Problem: https://www.hackerrank.com/challenges/attending-workshops/problem
*/


#include<bits/stdc++.h>

using namespace std;

#include <vector>
#include <algorithm>

//Define the structs Workshops and Available_Workshops.
struct Workshop
{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops
{
    int n;                      //number of workshops student signed up for
    std::vector<Workshop> my_array;

    //constructor
    Available_Workshops(int &num)
    {
        n = num;
        my_array = std::vector<Workshop>(n);
    }
};


//create a function that returns a pointer of type struct Available_Worshop
Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    //allocate memory for Available_Workshop struct
    Available_Workshops* arr = new Available_Workshops(n);


    //initialize the Available workshop
    for (int i{0}; i < n; i++)
    {
        arr->my_array[i].start_time = start_time[i];
        arr->my_array[i].duration = duration[i];
        arr->my_array[i].end_time = start_time[i] + duration[i];
    }

    //sort the end times of the array that is in Available_Workshops struct
    std::sort(arr->my_array.begin(), arr->my_array.end(), [](Workshop &w1, Workshop &w2)
    {
        return w1.end_time < w2.end_time;
    });

    return arr;
}

//CalculateMaxWorkshops
int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int end_time{0};
    int count{0};

    for (int i{0}; i < ptr->n; i++)
    {
        if(ptr->my_array[i].start_time >= end_time)
        {
            end_time = ptr->my_array[i].end_time;
            count++;
        }
    }

    return count;
}


int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
