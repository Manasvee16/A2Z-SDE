class Solution {
  public:
    int nthRoot(int n, int m) {
        long long start=1,end=m, mid=0, ans=-1;
        while (start<=end)
        {
            mid=start+(end-start)/2;
            int prod=mid;
            for (int i=1;i<n;i++)
            {
                prod=prod*mid; // compute mid^n
                if (prod>m)
                {
                    break;
                }
            }
            if (prod==m)
            {
                ans=mid; //current mid is the exact integer nth root of m
                break;
            }
            else if (prod<m)
            {
                start=mid+1; //We need a larger base
            }
            else
            {
                end=mid-1; //we need smaller base

            }
        }
        return ans;
    }
};
