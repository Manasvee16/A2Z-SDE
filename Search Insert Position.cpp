class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0, end=nums.size(), ans=0; //range [start, end)
        while (start<end)
        {
            int mid=start+(end-start)/2;
            if (nums[mid]>target)
            {
                end=mid; //That means target must be on the left half (maybe even at mid). 
              /*The valid indices to check are from start to end - 1. 
                So mid is still part of the valid range. 
              We shouldn’t discard mid unless we’re sure it’s invalid*/
            }
            else if(nums[mid]<target)
            {
                ans=mid+1; // target would be inserted right after mid
                start=mid+1;
            }
            else
            {
                ans=mid; // we found the exact index.
                return ans;
            }
        }
        return ans;
    }
};
