// GFG: https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1#
// LeetCode: https://leetcode.com/problems/find-the-duplicate-number/
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> res;
        // incrementing by n
        for(int i=0; i<n; i++) {
            arr[arr[i]%n] = arr[arr[i]%n] + n;
        }
        bool flag = false;
        for(int i=0; i<n; i++) {
            if(arr[i] >= 2*n) {
                res.push_back(i);
                flag = true;
            }
        }
        if(!flag)
            res.push_back(-1);
        return res;
    }
};