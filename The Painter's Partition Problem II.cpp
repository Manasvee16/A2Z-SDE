class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        if (k==1)
            return accumulate(arr.begin(), arr.end(), 0);
        int start=*max_element(arr.begin(), arr.end());
        int end=accumulate(arr.begin(), arr.end(), 0);
        int ans=0;
        while (start<=end)
        {
            int mid=start+(end-start)/2;
            if (isSplitPossible(mid, k, arr))
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
    bool isSplitPossible(int maxTime, int k, vector<int>& arr)
    {
        int count=0;
        int timee=0;
        for (int i=0;i<arr.size();i++)
        {
            timee+=arr[i];
            if (arr[i]>maxTime)
                return false;
            if (timee>maxTime)
            {
                count++;
                timee=arr[i];
            }
        }
        if (count>k-1)
            return false;
        return true;
    }
};
