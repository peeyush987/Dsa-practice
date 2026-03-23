/*
Problem: trapping rain water
Link: https://leetcode.com/problems/trapping-rain-water/
difficulty: Hard


approach:
    Used two pointers to track which side has the limiting factor then calculated water accordingly

Complexities:
    time: O(n) | O(1)
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n -1, leftmax = height[0], rightmax = height[n-1], result = 0;
        while(left <= right)
        {
            if(height[left] <= height[right])
            {
                leftmax = max(leftmax, height[left]);
                result += max(0, leftmax -height[left]);
                left++;
            }
            else
            {
                rightmax = max(rightmax, height[right]);
                result += max(0, rightmax - height[right]);
                right--;
            }
        }
        return result;
    }
};