class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int n=nums.size();
        int cnt0=0,cnt1=0,cnt2=0,i;
        for(int i=0;i<n;i++)
        {
            if (nums[i]==0)
                cnt0++;
            else if (nums[i]==1)
                    cnt1++;
            else
                cnt2++;
        }
        for (i=0;i<cnt0;i++)
            nums[i]=0;
        for (i=cnt0;i<cnt0+cnt1;i++)
            nums[i]=1;
        for (i=cnt0+cnt1;i<cnt0+cnt1+cnt2;i++)
            nums[i]=2;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
    int mid=0, low=0, high=nums.size()-1;
    while(mid<=high)
    {
        if (nums[mid]==0)
        {
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        }
        else if (nums[mid]==1)
            mid++;
        else
        {
            swap(nums[mid], nums[high]);
            high--; //no mid++ because we are missing out on one element
        }
    }
    }
};
