class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size()==1)
            return nums[0];
        int start=0, end=nums.size()-1; 
        int target=INT_MAX;
        while (start<=end)
        {
            int mid=start+(end-start)/2; 
            if (nums[mid]<target)
                target=nums[mid];
            if (nums[end]<nums[mid]) //then the smallest value must be on the right side
                start=mid+1;
            else //pivot must be at mid or on the left
                end=mid-1;
        }
        return target;
    }
};
