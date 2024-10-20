/*
Best Time To Buy And Sell Stocks:

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) 
    {
        int length = prices.size();
        int l = 0;
        int r = 1; 
        int maxProfit = 0;

        //ex: prices = [7,1,5,3,6,4]
        //              ^ ^
        //              l r

        while (r < length)  //while our right pointer hasn't passed the end of the array
        {
            if (prices[l] < prices[r])  //if it's profitable
            {
                int profit = prices[r] - prices[l];    //right (high) - left (low) 
                maxProfit = std::max(maxProfit, profit);
            }
            else //if it's not profitable
                l = r;          //shift left pointer all the way to the right
            
            r += 1;     //iterate to next element
        }
        return maxProfit;

    }
};
