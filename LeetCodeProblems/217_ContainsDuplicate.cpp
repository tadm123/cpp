/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

/* Brute Force: Sorting and comparing adjacent values */
/* Space complexity O(1), Time Complexity O(nlogn) */

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


/* Using Set and pointers for most efficient code */
/* Space complexity O(n), Time Complexity O(n). Sacrificing space for a faster time complexity */

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) 
    {
        std::unordered_set<int> intSet;
        int length{static_cast<int>(nums.size())};
        int curr;

        for (curr = 0; curr < length; curr++)
        {
            int num = nums[curr];    //get each element of the array
            if (intSet.count(num))   // if current element is in set (duplicate found) return true
            {
                //if duplicate found
                return true;
            }
            intSet.insert(num);       // if it doesn't contain duplicate, then add value into set
        }

        return false;
    }
};
