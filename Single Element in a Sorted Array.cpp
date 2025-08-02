class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=1, end=nums.size();
        if (nums.size()==1)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        while (start<end) //why start<end?
/*You're searching for a single non-duplicate in a sorted array where all other elements appear in pairs. 
The binary search eliminates half of the array at each step. 
Eventually, start will point to the unique element.
Once you reduce the search to a single element (i.e., start == end), the loop terminates. 
You can return nums[start] directly*/
        {
            int mid=start+(end-start)/2;
            if (nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];
            if (mid%2==0) //even
            {
                if (nums[mid-1]==nums[mid]) //go left because pair starts at odd index
                    end=mid;
                else
                    start=mid+1;
            }
            else
            {
                if (nums[mid-1]==nums[mid]) //go right
                    start=mid+1;
                else
                    end=mid;
            }
        }
        return -1;
    }
};
