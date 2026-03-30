/*
Problem: Minimum Difference Between Highest and Lowest of K Scores
Link: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
Difficulty: Easy

Complexities: 
    time: O(n log n) | space: O(1)

*/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size(), score = INT_MAX, left = 0, right = k-1;
        sort(nums.begin(), nums.end());
        while(right < n)
        {
            score = min(score, nums[right++] - nums[left++]);
        }
        return score;
    }
};