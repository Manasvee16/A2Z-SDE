class Solution 
{
public:
    bool check(vector<int>& nums) 
    {
        int count=0;
        int n=nums.size();
        for (int i=0;i<n;i++) 
        {
            if (nums[i]>nums[(i+1)%n]) 
                count++;
        }
        return count<=1;
      //If count == 0, the array is fully sorted in non-decreasing order, acceptable
      //If count == 1, the array is sorted except for one rotation point, acceptable
      //If count > 1, the order breaks in multiple places, not acceptable
    }
};
