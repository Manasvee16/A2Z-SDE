class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1; //smallest divisor
        int end=*max_element(nums.begin(), nums.end()); //no element should be divided by a number greater than itself.
        int ans=0;  
        while (start<=end)
        {
            int mid=start+(end-start)/2;
            if (sumPossible(mid,threshold,nums))
            {
                ans=mid;
                end=mid-1; //we want the smallest possible
            }
            else
            {
                start=mid+1; //If the current divisor is too small, the sum becomes too large, so we need to try larger divisors.
            }
        }
        return ans;
    }
    bool sumPossible(int divisor, int threshold, vector<int>& nums)
    {
        int sum=0;
        for (int i=0;i<nums.size();i++)
        {
            sum+=(ceil)((double)nums[i]/divisor);
        }
        if (sum<=threshold)
            return true;
        return false;
    }
};
