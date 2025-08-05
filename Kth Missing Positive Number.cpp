class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num=1,i=0,ans=0;
        while(k>0)
        {
            if (i<arr.size() && num==arr[i])
                i++;
            else
            {
                ans=num;
                k--;
                if (k==0)
                    return ans;
            }
            num++;
        }
        return -1;
    }
};

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1; //We will search over the index positions of the array.
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
           //how many numbers are missing till index mid = actual number at index mid - what the number should have been at position mid if there were no missing numbers + 0 based indexing
            if (missing < k) {
                low = mid + 1; //mid is still before the k-th missing number.
            } 
            else {
                high = mid - 1; //mid is after the k-th missing number.
            }
        }
        // low points to the position where the k-th missing number should be inserted.
        return low + k; //low numbers are not missing.
      /*some numbers are present in arr, we’ve shifted some of them to the right — by exactly low positions 
      (because low elements are present in the array before the k-th missing number).
        So we need to add low to k to “skip” the numbers that are already present.*/
    }
};
