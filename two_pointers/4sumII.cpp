/*
Problem: 4Sum II
Link: https://leetcode.com/problems/4sum-ii/
Difficulty: Medium

Approach:
Split the four arrays into two pairs: (nums1, nums2) and (nums3, nums4).
1. Use a hash map to store all possible sums of (nums1[i] + nums2[j]) 
   along with their frequencies.
2. Iterate through (nums3[k] + nums4[l]), calculating the 'target' 
   needed to reach zero (target = -(nums3[k] + nums4[l])).
3. If the target exists in the map, add its frequency to the total count.

Complexities:
    space: O(n^2) | time: O(n^2)
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int, int> sumCounts;
        for (int i : nums1) {
            for (int j : nums2) {
                sumCounts[i + j]++;
            }
        }

        for (int k : nums3) {
            for (int l : nums4) {
                int target = -(k + l);
                if (sumCounts.find(target) != sumCounts.end()) {
                    count += sumCounts[target];
                }
            }
        }

        return count;
    }
};