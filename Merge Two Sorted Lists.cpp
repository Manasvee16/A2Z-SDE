class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        // Traverse both lists while neither is null
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1; // link to list1's current node
                list1 = list1->next; // move list1 forward
            } 
            else {
                current->next = list2; // link to list2's current node
                list2 = list2->next; // move list2 forward
            }
            current = current->next; // move current forward
        }
        // If one list is not yet empty, attach the rest
        if (list1 != nullptr) 
            current->next = list1;
        else if (list2 != nullptr) 
            current->next = list2;
        return dummy->next; // return head of the merged list (skip dummy)
    }
};
