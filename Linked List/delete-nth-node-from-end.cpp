// LeetCode: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Time Complexity: O(n)
// Space Complexity: O(1)

// main aim is to move the slow pointer (list size-n) times, so that it will reach to the target node.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for(int i=0; i<n; i++)
            fast = fast->next;
        
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        return dummy->next;
    }
};