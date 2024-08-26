/*
  Design a class named Box whose dimensions are integers and private to the class. The dimensions are labelled: length , breadth , and height .
  For more information see the problem: https://www.hackerrank.com/challenges/box-it/problem
*/


#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
class Box
{
    int m_l{};
    int m_b{};
    int m_h{};
 
 public:   
    //Default contructor
    Box() = default;
    
    //Parameterized contructor
    Box(int l, int b, int h)
    :m_l{l}, m_b{b}, m_h{h}
    {
    }
    
    //Copy constructor
    Box(const Box &box)
    :m_l{box.m_l}, m_b{box.m_b}, m_h{box.m_h}
    {
    }
    
    int getLength(){return m_l;}
    int getBreadth(){return m_b;}
    int getHeight(){return m_h;}
    long long CalculateVolume() 
    {
        long long volume = m_l;
                volume *= m_b;
                volume *= m_h;
                return volume;
    }
    
    //overloading < operator
    friend bool operator< (const Box& box1, const Box& box2); 
    
    //overloading << operator
    friend std::ostream& operator<< (std::ostream& out, const Box& box);
    
    
};


//Overload operator < as specified
//bool operator<(Box& b)
bool operator<(const Box& box1, const Box& box2) 
{
   if ( (box1.m_l < box2.m_l) 
     || ( (box1.m_b < box2.m_b) && (box1.m_l == box2.m_l) )
     || ((box1.m_h < box2.m_h) && (box1.m_b == box2.m_b) && (box1.m_l == box2.m_l)  ) )
     return true;
     
    else
     return false;
   
}

std::ostream& operator<< (std::ostream& out, const Box& box) 
{ 
    out << box.m_l << " " << box.m_b << " " << box.m_h; 
    return out; 
} 


//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
