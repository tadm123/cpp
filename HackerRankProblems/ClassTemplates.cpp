/*
Class templates:
https://www.hackerrank.com/challenges/c-class-templates/problem
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T>
class AddElements
{
    T m_elem;
public:
    AddElements(T &elem)
    :m_elem(elem)
    {
    }

    T add(T &my_elem2)      
    {
        return m_elem + my_elem2;
    }

};


//template class specialization
template<>
class AddElements<std::string>
{
    std::string m_str;
public:
    AddElements(std::string &str)
    :m_str(str)
    {
    }
     std::string concatenate(std::string &my_str2)
     {
         return m_str + my_str2;
     }
};

//to speed up, The static start_up function speeds up cout and #define changes endl to '\n', that prevents flushing buffer for each line. 
int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

int static r = start_up();

#define endl '\n';

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}
