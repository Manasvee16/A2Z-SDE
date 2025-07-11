class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int n = nums.size();
        int lp = 1; //product of subarray starting from the left.
        int rp = 1; //product of subarray starting from the right.
        int ans = INT_MIN; //max product found so far
        for(int i=0 ; i<n ; i++)
        { //traverse the array from both ends simultaneously
        //multiply with current elements
            lp*=nums[i];
            rp*=nums[n-i-1];
            ans = max({ans,lp,rp});
            if(lp==0) 
                lp=1;
            if(rp==0) 
                rp=1;
        }
        return ans;
    }
};
/*In product subarray problems, a negative number may turn into a positive product if multiplied by another negative.
So, it's crucial to consider prefixes from both left and right ends.*/
