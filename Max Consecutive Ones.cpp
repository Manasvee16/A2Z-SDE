class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int count=0;
        int maxm=0;
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]==1)
            {
                count++;
            }
            else
            {
                maxm=max(maxm,count);
                count=0;
            }
        }
        return max(maxm,count);
    }
};
