/*
Problem: 3Sum Closest
link: https://leetcode.com/problems/3sum-closest/description/
difficulty: Medium



approach: 
    sort the array in increasing order
    iterate over each element
    take two pointers beyond the index you are iterating to get your second and third number for three sum
    now calculate the difference betweeen sum and target if it differs by less than what we have we update it and update the result to be current sum 
    if sum is more than target we move left pointer and vice versa, in search of the closest sum to target
    once we the loop ends we have the closest sum with us we return it.

Complexities:
    time: O(n^2) | space : O(1)
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, result = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int left = i+1, right = nums.size()-1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < diff)
                {
                    result = sum;
                    diff = abs(sum - target);
                }
                if(sum > target) right--;
                if(sum < target) left++;
                if(sum == target) return result;
            }
        }
        return result;
    }
};