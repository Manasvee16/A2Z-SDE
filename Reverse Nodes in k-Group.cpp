class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || head->next == nullptr )
            return head;
        ListNode *temp=head;
        ListNode* end = head, *start=head;
        for (int i=1;i<k;i++)
        {
            end=end->next;
            if (end==nullptr) //there are less than k nodes remaining. So, return the head without reversing
                return head;
        }
        ListNode * nextNode = reverseKGroup(end->next,k); //Recursively reverse the remaining part of the list after this group
        reverse(start,end); //start becomes the end of the reversed group, end becomes the new head of the group
        start->next = nextNode; //Link the last node of the reversed segment
        return end; 
    }
    void reverse(ListNode* start, ListNode* end)
    {
        ListNode* curr = start;
        ListNode* prev = nullptr;
      //curr will walk through the nodes, prev tracks the new reverse connection
        while (prev!=end) { //we stop after the last reversal (when prev == end)
            ListNode* nextNode = curr->next; // store next node
            curr->next = prev; // reverse current's pointer
            prev = curr; // move prev to current
            curr = nextNode; // move to next node
        }
    }
};
//TC O(N)
