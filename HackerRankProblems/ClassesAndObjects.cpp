/*

Create a class named Student with the following specifications:

An instance variable named scores to hold a student's  exam scores.
A void input() function that reads  integers and saves them to scores.
An int calculateTotalScore() function that returns the sum of the student's scores.

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <array>

// Write your Student class here
class Student{
    std::array <int,5> scores;
    public:
    void input(){
        for(int i=0; i<5; i++){
            cin >> scores[i];
        }
    }
    int calculateTotalScore(){
        int total = 0;
        for(int i=0; i<5; i++){
            total += scores[i];
        }
        return total;
    }
};


int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
