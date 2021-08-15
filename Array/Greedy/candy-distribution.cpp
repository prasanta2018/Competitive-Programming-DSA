// LeetCode
// https://leetcode.com/problems/candy/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> L2R, R2L;
        for(int i=0; i<n; i++) {
            L2R.push_back(1);
            R2L.push_back(1);
        }
        // for Left to Right
        for(int i=1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) {
                L2R[i] = L2R[i-1] + 1;
            }
        }
        // for Right to Left
        for(int i=n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) {
                R2L[i] = R2L[i+1] + 1;
            }
        }
        // counting
        int count = 0;
        for(int i=0; i<n; i++) {
            if(L2R[i] > R2L[i])
                count = count + L2R[i];
            else {
                count = count + R2L[i];
            }
        }
        return count;
    }
};