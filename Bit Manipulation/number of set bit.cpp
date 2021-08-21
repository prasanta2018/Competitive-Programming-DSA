// LeetCode: https://leetcode.com/problems/number-of-1-bits/

// Time Complexity: O(logn)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // solution-1
        if(0) {
            int count = 0;
            for(int i=0; i<32; i++) {
                if(n & (1 << i))
                    count++;
            }
            return count;
        }
        // solution-2
        // Brian Kernighan’s Algorithm: (https://www.geeksforgeeks.org/count-set-bits-in-an-integer/)
        if(0) {
            int count = 0;
            while(n) {
                n = n&(n-1);
                count++;
            }
            return count;
        }
        // solution-3
        int count = 0;
        while(n > 0) {
            if(n&1)
                count++;
            n = n >> 1;
        }
        return count;
    }
};