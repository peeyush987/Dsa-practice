/*
121. Best Time to Buy and Sell Stock
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
Difficulty: Easy
complexity:
Time: O(n) where n is the number of days (length of the input array). We iterate through the array once to find the minimum price and calculate the maximum profit, resulting in O(n) time complexity.
space: O(1) since we are using only a constant amount of extra space to store the minimum price and maximum profit, the space complexity is O(1).
Approach: One Pass
explanation: We can solve this problem in one pass by keeping track of the minimum price we have seen so far and the maximum profit we can achieve. We initialize the minimum price to the first element of the array and the maximum profit to 0. As we iterate through the array, we update the maximum profit by comparing the current price minus the minimum price with the current maximum profit. We also update the minimum price if we find a lower price. By the end of the iteration, we will have the maximum profit that can be achieved from a single buy and sell transaction. This approach allows us to find the solution in O(n) time complexity, since we are iterating through the array only once.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    int min_price = prices[0];
    int max_profit = 0;

    for (int i = 1; i < n; i++) {
        
        max_profit = max(max_profit, prices[i] - min_price);
        
        min_price = min(min_price, prices[i]);
    }

    return max_profit;
}

};