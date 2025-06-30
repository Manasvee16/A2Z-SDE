class Solution {
public:
    string getPermutation(int n, int k) {
        string permutations="";
        vector<int> nums;
        for (int i=1;i<=n;i++)
        {
            nums.push_back(i); //create number in the vector
        }
        for (int i=0;i<k-1;i++)
        {  
            nextPermutation(nums);
        }
        for (auto i:nums)
        {
            permutations+=(i+'0'); //push elements of vector into the string
        }
        return permutations;
    }
     void nextPermutation(vector<int>& nums) {
        int dip=-1;
        int n=nums.size();
        for (int i=n-2;i>=0;i--)
        {
            if (nums[i]<nums[i+1])
            {
                dip=i;
                break;
            }
        }
        if (dip==-1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        for (int i=n-1;i>dip;i--)
        {
            if (nums[dip]<nums[i])
            {
                swap(nums[dip], nums[i]);
                break;
            }
        }
        reverse(nums.begin()+dip+1, nums.end());
    }
};
//tc o(N*K)
