/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());

        for (auto it{nums.begin()}; it != nums.end()-1; ++it)
        {
            if ( *it == *(it+1) )
            {
                return true;
            }
        }
        return false;
    }
};

