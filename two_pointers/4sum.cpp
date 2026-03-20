/*
Problem: 4sum
Link: https://leetcode.com/problems/4sum/
Difficulty: medium


Approach:
    Sort the array into increasing order
    take(fix) two elements and then use two pointer approach beyond those elements
    the two pointer methods looks for the complement of the two fixed numbers

example:
    fixed: -2, -1
    remaining: 0, 1, 2
    target = 0 → need sum = 3 from remaining → (1,2)

    use two nested loops to fix i and j
    then apply two pointers (left, right) on the remaining part

    skip duplicates:
        for i
        for j
        for left and right after finding valid quadruplet

Time: O(n*n*n) | space: O(1) or O(k) including result
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> result;
        for(int i = 0; i < size; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i+1; j < size; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j+1, right = size - 1;
                while(left < right)
                {
                    int a = nums[left], b = nums[right], c = nums[i], d = nums[j];
                    long long sum = (long long)a + b + c + d;
                    if(sum > target) right--;
                    else if(sum < target) left++;
                    else
                    {
                        result.push_back({a,b,c,d});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left-1]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    }
                }
            }
        }
        return result;
        
    }
};