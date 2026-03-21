/*
Problem: Remove Duplicates from sorted array II
Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
difficulty: medium


approach:
    we simply count the elemnent previous to current element.
    remember we are allowed to have every element appearing twice only
    if previous is not equal which is the case initially we have index initialized as 0 so we have just replaced nums at 0 with nums at 0 and incremented the index
    if the previous is same and count is less than we simply replace the number with same index and increment the index
    if a number appears thrice we just set previous to that number and do no imcrement index
    so later in our code when next number appears it replaces the third appearance of previous element hance limmit every occurence by 2

Complexities:
    time: O(n) | space: O(1)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, prev = INT_MIN, prevcount;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != prev)
            {
                prevcount = 0;
                nums[index++] = nums[i];
                prevcount++;
            }
            else if(nums[i] == prev && prevcount < 2)
            {
                nums[index++] = nums[i];
                prevcount++;
            }
            prev = nums[i]; 
        }
        return index;
    }
};