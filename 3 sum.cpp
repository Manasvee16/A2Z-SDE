class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans; //to store triplets ensures automatic duplicate removal and they are stored in sorted order
        vector<vector<int>> temp;
        sort(nums.begin(), nums.end()); //ensures Efficient two-pointer scanning and Easily skipping duplicates
        for (int i=0;i<nums.size();i++)
        { //fix first no.
            int l=i+1, r=nums.size()-1;
            int sum=0;
            while (l<r)
            {//traverse to find two nos.
            sum=nums[i]+nums[l]+nums[r];
            if (sum==0)
            {
                ans.insert({nums[i], nums[l], nums[r]});
               l++, r--;
            }
            else if (sum>0) //sum is too big
                r--;
            else //sum is too small
                l++;
            }
            
        }
        for (auto i:ans)
        {
            temp.push_back(i);
        }
        return temp;
    }
};
//TC O(N^2)
//SC O(N)
