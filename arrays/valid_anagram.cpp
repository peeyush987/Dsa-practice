/*
Problem: 242. Valid Anagram
Link: https://leetcode.com/problems/valid-anagram/
Difficulty: Easy
complexity:
Time: O(n)
space: O(1)
Approach: Frequency Count
explanation: We can use a frequency count approach to determine if two strings are anagrams. 
We create a frequency array of size 26 (assuming only lowercase letters) to count the occurrences of each character in the first string and then decrement the counts based on the second string. 
If any count is not zero at the end, it means the two strings are not anagrams, and we return false. If all counts are zero, we return true, indicating that the two strings are anagrams
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freq(26, 0);

        for (char c : s) freq[c - 'a']++;
        for (char c : t) freq[c - 'a']--;

        for (int x : freq)
            if (x != 0) return false;

        return true;
    }
};