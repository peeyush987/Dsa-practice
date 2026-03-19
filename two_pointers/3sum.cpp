/*
Problem: 3sum
Link: https://leetcode.com/problems/3sum/
Difficulty: medium


Approach:
    Sort the array into increasing order
    take(fix) one element and then use two pointer approach beyond that element
    the two pointer methods looks for the complement of the number taken(fixed)
    example: -1(fixed) -1, 0, 1 (here two pointers helps in selecting 0 and 1 whose sum = 1(complement of fixed number))

Time: O(n*n) | space: O(1) or O(k) including result
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     sort(nums.begin(), nums.end());
     vector<vector<int>> result;
     for(int i = 0; i < nums.size(); i++)
     {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int left = i + 1, right = nums.size() - 1;
        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if(sum > 0) right--;
            else left++;
        }
     }
     return result;
    }
};