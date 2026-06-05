/*
Problem: 217. Contains Duplicate
Link: https://leetcode.com/problems/contains-duplicate/
Difficulty: Easy    
complexity:
Time: O(n)
space: O(n) 

Approach: Hash Map
explanation: We can use a hash map to keep track of the count of each number in the array. If we encounter a number that is already in the hash map, it means we have found a duplicate, and we can return true. If we finish iterating through the array without finding any duplicates, we return false.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i : nums)
        {
            if(map.count(i)) return true;
            map[i]++;
        }
        return false;
    }
};