class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int start=0,end=nums.size()-1;
        ans[0]=startpos(nums, start, end, target);
        ans[1]=endpos(nums, start, end, target);
        return ans;
    }
    int startpos(vector<int>& nums, int start, int end, int target)
    {
        int ans=-1;
        while (start<=end) //It guarantees we check all possible positions, including the case when only one element is left (start == end). It avoids missing target in edge cases like small arrays or when the target is at the start or end.
        {
            int mid=start+(end-start)/2;
            if (nums[mid]==target)
            {
                ans=mid;
                end=mid-1; //find an earlier occurrence.
            }
            else if (nums[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans; //Returns the first (leftmost) index of target found.
    }
    int endpos(vector<int>& nums, int start, int end, int target)
    {
        int ans=-1;
        while (start<=end) //same as startpos
        {
            int mid=start+(end-start)/2;
            if (nums[mid]==target)
            {
                ans=mid;
                start=mid+1; // find the last occurrence
            }
            else if (nums[mid]<target)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans; //Returns the last (rightmost) index of target found
    }
};
