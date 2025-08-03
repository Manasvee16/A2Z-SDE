class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int n=a.size();
        int m=b.size();
        if (n>m)
            return kthElement(b,a,k);
        int start=max(0, k-m); 
      /*You can’t take more than m elements from b, so:
        mid2 = k - mid1 ≤ m
      ⟹ mid1 ≥ k - m
        So, minimum you can take from a is k - m (but not less than 0).*/
        int end=min(k,n); 
      /*You can’t take more than n elements from a, so:
        mid1 ≤ n
      Also, mid2 = k - mid1 ≥ 0 
        ⟹ mid1 ≤ k
      So the max you can take from a is min(k, n)*/
        while (start<=end)
        {  //mid1+mid2==k
            int mid1=start+(end-start)/2; //no. of elements picked from a
            int mid2=k-mid1; //no. of elements picked from b
          //This ensures we are always considering exactly the k smallest elements from the combined arrays.
             int maxLeft1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
            int minRight1 = (mid1 == n) ? INT_MAX : a[mid1];
            int maxLeft2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
            int minRight2 = (mid2 == m) ? INT_MAX : b[mid2];
            if (maxLeft1<=minRight2 && maxLeft2<=minRight1)
            { 
                return max(maxLeft1, maxLeft2); 
            }
            else
            {
                if(maxLeft1>minRight2)
                {
                    end=mid1-1;
                }
                else 
                {
                    start=mid1+1;
                }
            }
        }
        return -1;
    }
};
