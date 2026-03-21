/*
Problem: Boats to Save people
Link: https://leetcode.com/problems/boats-to-save-people/
Difficulty: medium


approach:
    we know each boat can carry 2 people at max
    we use two pointers to track the lightest and heaviest person
    we try to fit them both if they do fit we move forward to next lighest and next heaviest 
    if the lightest and heaviest can not fit we add one boat for the heaviest and decrement right
    and eventually get the number of boats required

Complexities:
    time: O(n) | space : O(1)
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int l = 0, r = people.size() - 1;
        int boats = 0;

        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                l++;
            }
            r--;
            boats++;
        }

        return boats;
    }
};