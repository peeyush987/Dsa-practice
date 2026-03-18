/*
Problem: Substring with Concatenation of All Words
Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
Difficulty: Hard


Pattern Trigger:
 Find all starting indices of substrings formed by concatenation of all words (same length)
Keywords: fixed-size chunks, all words must match, permutation allowed → sliding window + hashmap + offsets
Core Idea:
    Traverse string in word-length chunks for each offset (0 → wordLen-1)
Use:
    frequency map (required words)
    window map (current counts)
Expand window:
    add word if valid
Shrink window:
    if frequency exceeds (remove from left)
Reset:
    if invalid word appears
Record index:
    when all words match exactly
Time: O(n × wordLen) | Space: O(m)
(where m = number of words)
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int totalWords = words.size();
        int windowLen = wordLen * totalWords;

        unordered_map<string, int> wordCount;
        for (auto &w : words) wordCount[w]++;

        for (int i = 0; i < wordLen; i++) {
            int left = i, right = i;
            int count = 0;
            unordered_map<string, int> window;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordCount.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == totalWords) {
                        result.push_back(left);

                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                }
                else {
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};