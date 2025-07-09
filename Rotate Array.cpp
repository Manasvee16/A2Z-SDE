class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        vector<int> now=nums;
        for (int i=0;i<nums.size();i++)
        {
            now[(i+k)%nums.size()]=nums[i];
        }
        nums=now;
    }
};
