// LeetCode: https://leetcode.com/problems/longest-palindromic-substring/

// Dynamic Programming Approach
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)

class Solution {
public:
    string longestPalindrome(string s) {
        
        // Brute Force Approach
        // time - O(n^3) and space- O(1)
        if(0) {
            int n = s.length();
            // substring is having one character.
            int longestPalindromeLength = 1;
            int startIndex = 0;

            for(int i=0; i<n; i++) {
                for(int j=i; j<n; j++) {
                    bool flag = true;
                    // Palindrome Check
                    for(int k=0; k<(j-i+1)/2; k++) {
                        if(s[i+k] != s[j-k])
                            flag = false;
                    }

                    if(flag) {
                        if(longestPalindromeLength < (j-i+1)) {
                            longestPalindromeLength = j-i+1;
                            startIndex = i;
                        }
                    }
                }
            }
            return s.substr(startIndex,longestPalindromeLength);
        }
        
        // Dynamic Programming Approach
        // time - O(n^2) and space- O(n^2)
        if(1) {
            int n = s.length();
            int longestPalindromeLength = 1;
            int startIndex = 0;
            // to store the palindromic state of substrings
            bool dp[n][n];
            
            // intialize to zero
            memset(dp, 0, sizeof(dp));
            
            // all the length=1 substrings are palindrome
            for(int i=0; i<n; i++)
                dp[i][i] = true;
            // all the substrings are having length=2
            for(int i=0; i<n-1; i++) {
                if(s[i] == s[i+1]) {
                    dp[i][i+1] = true;
                    longestPalindromeLength = 2;
                    startIndex = i;
                }
            }

            // all the substrings are having length >= 3
            for(int k=3; k<=n; k++) {
                for(int i=0; i<n-k+1; i++) {
                    int j = i+k-1;
                    if(dp[i+1][j-1] && s[i]==s[j]) {
                        dp[i][j] = true;
                        if(k > longestPalindromeLength) {
                            startIndex = i;
                            longestPalindromeLength = k;
                        }
                    }                        
                }
            }
            return s.substr(startIndex,longestPalindromeLength);
        }
    }
};