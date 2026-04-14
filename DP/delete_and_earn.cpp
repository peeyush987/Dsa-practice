/*
Problem: Delete and earn
Link: https://leetcode.com/problems/delete-and-earn/
Difficulty: Medium 

complexity:
Time: O(nlogn)
space: O(n)
*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x] += x;
        }

        vector<int> values;
        for (auto &p : mp) values.push_back(p.first);
        sort(values.begin(), values.end());

        int n = values.size();
        vector<int> dp(n, 0);

        dp[0] = mp[values[0]];

        for (int i = 1; i < n; i++) {
            int take = mp[values[i]];
            
            if (values[i] == values[i - 1] + 1) {
                if (i > 1) take += dp[i - 2];
            } else {
                take += dp[i - 1];
            }

            int notTake = dp[i - 1];

            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }
};