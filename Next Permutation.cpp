class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dip=-1; //no dip found yet
        int n=nums.size();
        for (int i=n-2;i>=0;i--)
        {
            if (nums[i]<nums[i+1])
            {
                dip=i; //Find the rightmost "dip"
                break;
            }//This means the current permutation is not the largest
        }
        if (dip==-1)
        {
            sort(nums.begin(), nums.end()); //return the first permutation
            return;
        }
        for (int i=n-1;i>dip;i--)
        {
            if (nums[dip]<nums[i]) //Find the next greater element than dip from right and swap them
            {
                swap(nums[dip], nums[i]);
                break;
            }
        }// This ensures that we replace nums[dip] with the next smallest number greater than it from the suffix
        reverse(nums.begin()+dip+1, nums.end());
      //the right part is still in descending order. so we reverse it to make it the smallest permutation
    }
};
