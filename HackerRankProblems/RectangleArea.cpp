/*
Create two classes:
Rectangle
RectangleArea

Input Format:
The first and only line of input contains two space separated integers denoting the width and height of the rectangle.

Output Format

The output should consist of exactly two lines:
In the first line, print the width and height of the rectangle separated by space.
In the second line, print the area of the rectangle.
*/


#include <iostream>

/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle
{
protected:
    int m_width{};
    int m_height{};

public:
    Rectangle() = default;

    Rectangle(int width, int height)
            :m_width{width}, m_height{height}
    {
    }

    //Print the width and height
    virtual void display()
    {
        std::cout << m_width << " " << m_height << "\n";
    }
};

class RectangleArea: public Rectangle
{
public:
    RectangleArea() = default;

    RectangleArea(int width, int height)
    :Rectangle(width, height)
    {
    }

    void read_input()
    {
        std::cin >> m_width >> m_height;
    }

    //overloading << operator so it prints the area (multiplication of both)
    void display()
    {
        std::cout << m_width * m_height;
    }
};


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}
