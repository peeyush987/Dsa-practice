/*
Problem: 128. Longest Consecutive Sequence
Link: https://leetcode.com/problems/longest-consecutive-sequence/
Difficulty: Medium      
complexity:
Time: O(n) where n is the number of elements in the input array. We iterate through the array once to add elements to the set, and then we iterate through the set to find the longest consecutive sequence, resulting in O(n) time complexity.
space: O(n) since we are using a hash set to store the unique elements from the input array, the space complexity is O           (n) where n is the number of elements in the input array, because in the worst case, all elements are unique and we need to store all of them in the set.
Approach: Hash Set
explanation: We can use a hash set to store the unique elements from the input array. Then, we iterate through the set and for each number, we check if it is the start of a sequence (i.e., if the number one less than it is not in the set). If it is the start of a sequence, we keep checking for the next numbers in the sequence (i.e., number + 1, number + 2, etc.) and count the length of the sequence. We keep track of the longest sequence length found and return it at the end. This approach allows us to find the longest consecutive sequence in O(n) time complexity, since each number is processed at most twice (once when we check if it's the start of a sequence and once when we count the length of the sequence).

*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int longest = 0;

        for (int num : s) {
            if (!s.count(num - 1)) { // start of sequence
                int current = num;
                int length = 1;

                while (s.count(current + 1)) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};