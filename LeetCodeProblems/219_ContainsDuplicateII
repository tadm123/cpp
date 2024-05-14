/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {    
        for (int i{0}; i < nums.size()-1 ; ++i)
        {   
            for (int j{i}; j < nums.size()-1; ++j)
            {
                //compare i and j+1
                if (nums[i] == nums[j+1])
                {
                    if( abs(i- (j+1)) <= k )
                        return true;
                }
            }
        }
        return false;
    }
};

