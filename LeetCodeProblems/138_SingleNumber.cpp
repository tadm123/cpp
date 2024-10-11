/*
Single Number:
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

class Solution {
public:
    int singleNumber(std::vector<int>& nums) 
    {
        int result{0};                  //n^0 = n
        for (auto const& digit: nums)
        {
            result = digit^result;      //XOR
        }
        return result;
    }
};
