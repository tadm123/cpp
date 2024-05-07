/* 
Hackerank C++14 version.
Write a function int max_of_four(int a, int b, int c, int d) which returns the maximum of the four arguments it receives.

Input will contain four integers - a,b,c,d  , one per line.

Output Format

Return the greatest of the four integers.
PS: I/O will be automatically handled.
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


int max_of_four(int a, int b, int c, int d) //ex: 17 13 3 15
{
    int max{a}; 
    
    if (max<b)
        max = b;
    
    if (max<c)
        max = c;
        
    if (max<d)
        max = d;
   
    return max;
}


int main() 
{
    int a, b, c, d;
  *
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
