/*
Problem: Sliding Window Maximum
Link: https://leetcode.com/problems/sliding-window-maximum/description/
Difficulty: Hard


Pattern Trigger: Sliding window with need to find maximum in every window of size k
Core Idea: Use a monotonic deque (decreasing) to keep track of useful elements
Remove: elements out of window (from front)
        smaller elements (from back) since they’ll never be maximum
Time: O(n) | Space: O(k)
*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();

        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;

    }
};

