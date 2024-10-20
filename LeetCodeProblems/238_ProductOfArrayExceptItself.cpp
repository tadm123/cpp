/*
Product of Array Except Self:
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
*/

class Solution
{
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums)
	{
		auto res = nums;
		int postfix = 1;

		for (int i = 1; i < nums.size(); ++i)
		{
			res[i] *= res[i - 1];
		}

		for (int i = nums.size() - 1; i > 0; --i)
		{
			res[i] = postfix;
			res[i] *= res[i - 1];
			postfix *= nums[i];
		}
		res[0] = postfix;

		return res;
	}
};

