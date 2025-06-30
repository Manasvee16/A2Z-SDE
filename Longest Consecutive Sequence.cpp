class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty()) 
            return 0; 
        sort(nums.begin(), nums.end());
        int max_len = 1; 
        int current_len = 1;
        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] == nums[i - 1]) 
            {
                continue; 
            }
            if (nums[i] == nums[i - 1] + 1) 
            {
                current_len++;
                max_len = max(max_len, current_len);
            } 
            else 
            {
                current_len = 1; 
            }
        }
        return max_len;
    }
};
//TC O(N)
