class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int start=INT_MAX, end=INT_MIN;
        int n=mat.size(), m=mat[0].size();
        for (int i=0;i<n;i++)
        {
            start=min(start, mat[i][0]);
            end=max(end, mat[i][m-1]);
        }
        while (start<=end) //ensures we do not skip the final comparison, especially when start == end. This is important because the median might be exactly at that last value, and we want to evaluate it.
        {
            int mid=start+(end-start)/2; 
            int temp=(n*m)/2; //target position of the median.
            int count=0; //will store how many elements are <= to mid
            for (int i=0;i<n;i++)
            {
                count+=helper(mat[i], mid); // count the number of elements ≤ mid
            }
            if (count<=temp) //There are not enough elements ≤ mid to reach the median.
                start=mid+1;
            // else /There are more than enough elements ≤ mid
                end=mid-1;
        }
        return start; //first number that has more than (n×m)/2 elements ≤ it is start
    }
    int helper(vector<int> &mat, int comp)
    { //Returns number of elements ≤ comp in that row
        int low=0, high=mat.size()-1;
        int ans=mat.size(); //assuming all are ≤ comp
        while (low<=high)
        {
            int mid=low+(high-low)/2; 
            if (mat[mid]>comp) //all elements from index mid onward are also > 4.
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
