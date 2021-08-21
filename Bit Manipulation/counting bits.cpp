//LeetCode: https://leetcode.com/problems/counting-bits/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int Count1(int n) {
        int count = 0;
        while(n) {
            n = n&(n-1);
            count++;
        }
        return count;
    }

    vector<int> countBits(int n) {
        // O(nlogn) solution
        if(0) {
            vector<int> res;
            for(int i=0; i<=n; i++) {
                res.push_back(Count1(i));
            }
            return res;
        }
        // O(n) solution
        if(1) {
            vector<int> dp(n+1);
            dp[0] = 0;
            for(int i=1; i<=n; i++) {
                dp[i] = dp[i >> 1] + (i%2);
            }
            return dp;
        }
    }
};