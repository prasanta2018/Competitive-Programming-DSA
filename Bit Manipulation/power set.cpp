// LeetCode: https://leetcode.com/problems/subsets/

// Time Complexity: O(n*2^n)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        
        for(int i = 0; i < (1<<n); i++) {
            vector<int> temp;
            for(int j = n-1; j >= 0; j--) {
                if(i & (1 << j)) {
                    temp.push_back(nums[n-1-j]);
                }
            }
            res.push_back(temp);
        }
        return res;
        
    }
};