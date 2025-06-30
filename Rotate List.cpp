class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        ListNode* temp=head;
        int count=1;
        while (temp->next!=nullptr)
        {
            temp=temp->next;
            count++;
        }
        temp->next=head;
        k=k%count; //Reduce unnecessary full rotations
        for (int i=0;i<count-k;i++) //The last k nodes come to the front
        {
            temp=temp->next; //This places temp at the node before the new head
        }
        head=temp->next; //New head is k nodes from the end of the list
        temp->next=nullptr;
        return head;
    }
};
