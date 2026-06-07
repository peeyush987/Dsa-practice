/*
Problem: 238. Product of Array Except Self
Link: https://leetcode.com/problems/product-of-array-except-self/
Difficulty: Medium
complexity:
Time: O(n) where n is the length of the input array. We traverse the input array twice, once from left to right and once from right to left, resulting in O(n) time complexity.
space: O(1) if we don't consider the space used for the output array, since we are modifying the output array in place. However, if we consider the space used for the output array, the space complexity is O(n) where n is the length of the input array, because we are storing the product of all elements except self in a separate array.
Approach: Two Passes
explanation: We can use two passes to calculate the product of all elements except self. In the first pass, we calculate the product of all elements to the left of each index and store it in the output array. In the second pass, we calculate the product of all elements to the right of each index and multiply it with the corresponding value in the output array. This way we get the product of all elements except self for each index in the output array.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);

        int left = 1;
        for (int i = 0; i < nums.size(); i++) {
            output[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] *= right;
            right *= nums[i];
        }

        return output;        
    }
};