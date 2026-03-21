/*
Problem: Container With most water
Link: https://leetcode.com/problems/container-with-most-water/
Difficulty: Medium

approach:
    we use the two pointers left being the first bar right being the last bar
    we initialize maxwater as 0
    now as we move the water is limited by shorter bar as it will spill if we go over it 
    therefore we calculate the area 
    eventually we get the most water that can be stored

Complexities:
    time: O(n) | space: O(1)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() -1, maxwater = 0;
        while(l < r)
        {
            maxwater = max(maxwater,min(height[l], height[r]) * (r-l));
            if(height[l] < height[r]) l++;
            else r--;
        }
        return maxwater;
    }
};