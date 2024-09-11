/*
Operator Overloading:
https://www.hackerrank.com/challenges/operator-overloading/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




class Matrix
{
public:
    std::vector<std::vector<int> > a{};  
    
    //friend function overload operator+
    friend Matrix operator+(Matrix &x, Matrix &y);

};

Matrix operator+(Matrix &x, Matrix &y)
{
    int res;
    std::vector<int> myVect{};
    Matrix result;                               //initializing Matrix "result"
    for (int i{0}; i < x.a.size(); i++)            
    {
        myVect.clear();
        for (int j{0}; j < x.a[0].size(); j++)    //x.a[0].size gets you the size of the inner vector
        {
            res = x.a[i][j] + y.a[i][j];
            myVect.push_back(res);
        }
        result.a.push_back(myVect);
    }
    return result;
}


int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
