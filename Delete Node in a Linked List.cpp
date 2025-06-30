class Solution {
public:
    void deleteNode(ListNode* node) {
                node->val = node->next->val; // Copy the next node's value
        ListNode* temp = node->next; // Store next node temporarily
        node->next = node->next->next; // Bypass the next node
    }
};
