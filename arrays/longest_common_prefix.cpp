/*
Problem: 14. Longest Common Prefix
Link: https://leetcode.com/problems/longest-common-prefix/
Difficulty: Easy
complexity:
Time: O(n * m) where n is the number of strings in the input array and m is the length of the longest common prefix. In the worst case, all strings are the same, and we need to compare all characters of all strings, resulting in O(n * m) time complexity.
space: O(1) if we don't consider the space used for the output string, since we are modifying the prefix string in place. However, if we consider the space used for the output string, the space complexity is O(m) where m is the length of the longest common prefix, because we are storing the longest common prefix in a separate string variable.
Approach: Iterative
explanation: We can start by assuming that the longest common prefix is the first string in the input array. Then, we iterate through the rest of the strings in the array and compare them with the current longest common prefix. If the current string does not match the prefix, we reduce the length of the prefix by one character and check again until we find a match or the prefix becomes empty.         
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string pref = strs[0];
        int prefLen = pref.length();

        for (int i = 1; i < strs.size(); i++) {
            string s = strs[i];
            while (prefLen > s.length() || pref != s.substr(0, prefLen)) {
                prefLen--;
                if (prefLen == 0) {
                    return "";
                }
                pref = pref.substr(0, prefLen);
            }
        }

        return pref;        
    }
};