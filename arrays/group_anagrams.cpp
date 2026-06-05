/*
Problem: 49. Group Anagrams
Link: https://leetcode.com/problems/group-anagrams/ 
Difficulty: Medium
complexity:
Time: O(n * k log k) where n is the number of strings and k is the maximum length of a string in the input array. This is because we need to sort each string, which takes O(k log k) time, and we do this for all n strings.
space: O(n * k) in the worst case, where all strings are anagrams of each other, and we need to store all of them in the hash map. The space complexity is also O(n) for the output list of lists, but since we are already counting the space used by the hash map, we can consider the overall space complexity to be O(n * k).
Approach: Hash Map
explanation: We can use a hash map to group the anagrams together. The key of the hash map will be the sorted version of the string, and the value will be a list of strings that are anagrams of each other. We iterate through each string in the input array, sort it to get the key, and then add the original string to the list of anagrams in the hash map. Finally, we iterate through the hash map and add each group of anagrams to the result list.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map1;
        for(string str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            map1[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto &group : map1)
        {
            result.push_back(group.second);

        }
        return result;
    }
};