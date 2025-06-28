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
