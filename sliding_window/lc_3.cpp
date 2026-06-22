/*
Problem: 3. Longest Substring Without Repeating Characters
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
Difficulty: Medium
complexity:
Time: O(n) where n is the length of the input string. We iterate through the string once, and each character is processed at most twice (once when it is added to the map and once when it is removed), resulting in O(n) time complexity.
space: O(min(n, m)) where n is the length of the input string and m is the size of the character set (e.g., 26 for lowercase letters, 128 for ASCII characters). We use a hash map to store the characters and their indices, which requires space proportional to the number of unique characters in the string. In the worst case, all characters are unique, and we need to store all of them in the map, resulting in O(min(n, m)) space complexity.
Approach: Sliding Window
explanation: We can use a sliding window approach to find the longest substring without repeating characters. We maintain a window defined by two pointers, left and right, which represent the current substring. We also use a hash map to store the characters and their indices. As we iterate through the string with the right pointer, we check if the character at the right pointer is already in the map. If it is, we move the left pointer to the right of the last occurrence of that character to ensure that the substring remains unique. We update the map with the current character and its index, and calculate the length of the current substring. We keep track of the maximum length found during the iteration. This approach allows us to find the solution in O(n) time complexity, since we are iterating through the string only once, and each character is processed at most twice.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int left = 0, maxlen = 0;
        for(int right = 0; right < s.size(); right++)
        {
            if(map.count(s[right]))
            {
                left = max(left, map[s[right]] + 1);
            }
            map[s[right]] = right;
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};