// This project takes inputs from a user of two numbers and then adds them. 

#include "io.h"

int main()
{
    int x { readNumber() };
    int y { readNumber() };
    writeAnswer(x + y); // using operator+ to pass the sum of x and y to writeAnswer()

    return 0;
}
