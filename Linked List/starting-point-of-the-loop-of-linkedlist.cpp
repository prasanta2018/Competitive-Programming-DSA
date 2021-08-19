// LeetCode: https://leetcode.com/problems/linked-list-cycle-ii/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // findling clasing point where slow meets fast
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                break;
            }
        }
        // CHecking for no cycle
        if(fast == NULL || fast->next == NULL)
            return NULL;
        
        ListNode* start = head;

        // finding the clasing point of start and fast as per mathematical intution
        while(start != slow) {
            start = start->next;
            slow = slow->next;
        }
        return slow;        
    }
};