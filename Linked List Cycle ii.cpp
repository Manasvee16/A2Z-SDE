class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        if (!head || head->next == nullptr) 
            return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // Step 2: Find start of cycle
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // cycle start node
            }
        }
        return nullptr; // No cycle
    }
};
