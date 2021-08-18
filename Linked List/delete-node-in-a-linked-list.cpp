// LeetCode: https://leetcode.com/problems/delete-node-in-a-linked-list/

// Time COmplexity: O(1)
// Space CIoplexity: O(1)

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;        
    }
};