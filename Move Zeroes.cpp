class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int start=0; //tracks the index where the next non-zero element should be placed
        for (int i=0;i<nums.size();i++)
        {
            if (nums[i]!=0)
            {
                nums[start]=nums[i]; //non-zero value is placed at the start
                start++;
            }
        }
        for (int i=start;i<nums.size();i++)
        {
            nums[i]=0;
        }
    }
};
