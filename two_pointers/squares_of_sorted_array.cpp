/*
Problem: Squares of Sorted Array
Link: https://leetcode.com/problems/squares-of-a-sorted-array/
Difficulty: Easy


Appraoch:
Since array is sorted, largest square will come from either left (negative) 
or right (positive). Use two pointers to compare absolute values.
Place the bigger square at the end of result array and move pointers inward.
Repeat until all elements are processed.

Comlexities:
    space: O(n) | time: O(n)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n -1, pos = n -1;
        vector<int> result(n);
        while(left <= right)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                result[pos--] = nums[left]*nums[left];
                left++;
            }
            else
            {
                result[pos--] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};