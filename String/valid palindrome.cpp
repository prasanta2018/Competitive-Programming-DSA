// LeetCode: https://leetcode.com/problems/valid-palindrome/

// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        // at a time only one statement should execute
        while(left < right) {
            if(!isalnum(s[left])) left++;
            else if(!isalnum(s[right])) right--;
            else if(tolower(s[left]) != tolower(s[right])) return false;
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};