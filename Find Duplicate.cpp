class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        // Phase 1: find meeting point inside the cycle
        do {
            slow = nums[slow];         // one step
            fast = nums[nums[fast]];   // two steps
        } while (slow != fast);
        // Phase 2: find cycle entry (duplicate)
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow; // duplicate value
    }
};
//TC O(2N)
//SC O(N)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=nums[0], slow=nums[0], n=nums.size();
        do
        {
            fast=nums[nums[fast%n]%n];
            slow=nums[slow%n];
           
        } while (slow!=fast);
        fast=nums[0];
        for (int i=0;i<nums.size() && slow!=fast;i++)
        {
            fast=nums[i+1]; 
            slow=nums[i+1]; 
        }
        return slow;
    }
};
//TC O(2N)
