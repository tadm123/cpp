/*
Two Sum:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) // nums = [2, 7, 11, 15], nums[0]
    {
        std::unordered_map<int, int> prevMap{};     // val : index prevMap(value, index)
        int length = static_cast<int>(nums.size());
        int diff;

        for(int i{0}; i < length; i++)
        {
            diff = target - nums[i];
            if ( prevMap.count(diff) )  //if the difference (value) is on our hashmap, .count method returns the index
                return {prevMap[diff], i};      //return the pair of indexes where it was found

            prevMap[nums[i]] = i;       //adding to hashmap
        }

        return {};      //no solution found
    }
};
