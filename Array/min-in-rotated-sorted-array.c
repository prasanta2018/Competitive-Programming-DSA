// Company: Soroco
// LeetCode: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.
/*
Input: nums = [3,4,5,1,2]
Output: 1
Input: nums = [11,13,15,17]
Output: 11
*/

class Solution {
public:
    
    int findMinimum(vector<int>& a, int low, int high) {
        if(a[low] < a[high])
            return a[low];
        if(low == high)
            return a[low];
        int mid = (high + low)/2;
        if(a[mid] < a[mid+1] && a[mid] < a[mid-1])
            return a[mid];
        if(a[high] > a[mid])
            return findMinimum(a, low, mid-1);
            return findMinimum(a, mid+1, high);      
    }

    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        return findMinimum(nums, low, high);
    }
};