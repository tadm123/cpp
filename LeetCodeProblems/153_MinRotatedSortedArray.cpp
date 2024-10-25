/*
Find Minimum in Rotated Sorted Array:
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that rns in O(log n) time.
*/


/* Using Binary Search. Time complexity: O(logn), Space complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int res{nums[0]};
        int l = 0;
        int r = static_cast<int>(nums.size()) - 1;

        while (l <= r)
        {
            if (nums[l] < nums[r])    //if array is already sorted as it is
            {
                res = std::min(res, nums[l]);      //get the left-most value 
                break;
            }
            else
            {
                int m = (l + r)/2;
                res = std::min(res, nums[m]);

                if (nums[m] >= nums[l]) //if we're on the left sorted portion
                    l = m + 1;
                else                    //if we're on the right sorted portion
                    r = m - 1;
                
            }
        }
        return res;
    }
};
