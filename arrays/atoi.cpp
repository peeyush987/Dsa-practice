/*
Problem: 8. String to Integer (atoi)
Link: https://leetcode.com/problems/string-to-integer-atoi/
Difficulty: Medium
complexity:
Time: O(n) where n is the length of the input string. We need to iterate through the string once to parse the integer, resulting in O(n) time complexity.
space: O(1) since we are using a constant amount of space to store the result and other variables, we can consider the space complexity to be O(1) as it does not depend on the input           
size.
Approach: Iterative         
explanation: We can iterate through the input string and parse the integer according to the rules specified in the problem. We start by skipping any leading whitespace characters. Then, we check for an optional sign character ('+' or '-'). After that, we read the digits and convert them into an integer. We also need to handle overflow and underflow cases by checking if the result exceeds the limits of a 32-bit signed integer. Finally, we apply the sign to the result and return it.       
*/
class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) {
            return 0;
        }
        
        // Use standard library constants
        const long long MAX_INT = INT_MAX;
        const long long MIN_INT = INT_MIN;
        
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Check if we've reached the end
        if (i == n) {
            return 0;
        }
        
        // Step 2: Check for sign
        int sign = 1;
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        
        // Step 3: Read digits and convert
        long long res = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            res = res * 10 + digit;
            
            if (sign * res <= INT_MIN) {
                return INT_MIN;
            }
            if (sign * res >= INT_MAX) {
                return INT_MAX;
            }
            
            i++;
        }
        
        // Step 4: Apply sign and return
        return static_cast<int>(res * sign);     
    }
};