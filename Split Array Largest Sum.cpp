class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        if (k==1) //you cannot split
            return accumulate(nums.begin(), nums.end(), 0);
        int n=nums.size();
        int start=*max_element(nums.begin(), nums.end()); //in any valid split, the max subarray sum can’t be less than the largest number.
        int end=accumulate(nums.begin(), nums.end(), 0); 
        int ans=0;
        while (start<=end)
        {
            int mid=start+(end-start)/2; 
            if (isSplitPossible(mid, nums, k)) //is it possible to split nums into ≤ k subarrays such that each subarray has sum ≤ mid.
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
    bool isSplitPossible(int maxSum, vector<int>& nums, int k)
     //whether you can split nums into at most k parts where each part has sum ≤ maxSum
        int count=0; //number of splits made.
        int ans=0; //running sum of current subarray.
        for (int i=0;i<nums.size();i++)
        {
            ans+=nums[i];
            if (nums[i]>maxSum) //If a single number is bigger than maxSum, we cannot split to satisfy this max
                return false;
            if (ans>maxSum)
            {
                count++; //make a split
                ans=nums[i]; //start a new subarray with the current number.
            }
        }
        if (count>k-1) //total subarrays > k
            return false;
        return true;
    }
};
