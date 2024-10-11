/*
Reverse Bits:
Reverse bits of a given 32 bits unsigned integer
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        
        uint32_t res = 0;

        for (int i{0}; i < 32; i++)
        {
            res = res << 1; //shift to left
            ans |= (n & 1); //always AND it with the right upmost digit
            n = n >> 1;     //shifts to right

        }

        return res;

    }
};
