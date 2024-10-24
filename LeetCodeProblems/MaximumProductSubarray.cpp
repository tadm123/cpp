/*
Maximum Product Subarray:
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
*/

class Solution {
public:
    int maxProduct(std::vector<int>& nums) 
    {
        int res = *std::max_element(nums.begin(), nums.end());
        int currMin{1};
        int currMax{1};

        for (const auto& n: nums)
        {
            if (n == 0)
            {
                currMin = 1;
                currMax = 1;
                continue;
            }
            int temp = n * currMax;
            currMax = std::max({n * currMax, n * currMin, n});
            currMin = std::min({temp, n * currMin, n});
            res = std::max(res, currMax);
        }
        return res;
    }
};
