class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) 
        { //start of subarray
            int sum = 0;
            for (int j = i; j < nums.size(); j++) 
            { //generates subarrays
                sum = sum + nums[j]; //sum of nums[i] to nums[j]
                if (sum == k) 
                    count++;
            }
        }
        return count;
    }
};
//TC O(N^2)
