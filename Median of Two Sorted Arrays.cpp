class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1); // Ensures binary search is always done on the shorter array to maintain O(log(min(n, m))) complexity.
        int x = nums1.size();
        int y = nums2.size();
        int low = 0, high = x; //Initialize binary search bounds for nums1
        while (low <= high) 
        { //We’re searching for the correct partition index — not a particular value. This means every index in the range is a possible valid partition, including when low == high
            int partX = (low + high) / 2; // current partition in nums1
            int partY = (x + y + 1) / 2 - partX; //the corresponding partition in nums2 such that left half = right half in size. +1 ensures correct median calculation when total elements are odd
            int maxLeftX = (partX == 0) ? INT_MIN : nums1[partX - 1];
            int minRightX = (partX == x) ? INT_MAX : nums1[partX];
            int maxLeftY = (partY == 0) ? INT_MIN : nums2[partY - 1];
            int minRightY = (partY == y) ? INT_MAX : nums2[partY];
          /*We want The total left half to contain exactly half the total elements.
            The maximum of the left half to be ≤ minimum of the right half.
            This guarantees all elements on the left are ≤ all elements on the right → ✅ Valid median partition.*/
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) 
            { //If any element on the left is greater than any element on the right, the middle is not properly located. if the boundaries obey the condition, the entire left side is ≤ the entire right side.
              /*You're simulating the merge
                The max of left and min of right are the two middle values
              Median is either their average (even) or just the max (odd)*/
              if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } 
                else { 
                    return max(maxLeftX, maxLeftY);
                }
            } 
            else if (maxLeftX > minRightY) { //This means maxLeftX is too big, and you need a smaller element from nums1 on the left. So reduce partX
                high = partX - 1;
            } 
            else { //partition in nums1 is too far left, and you need to include more from nums1.
                low = partX + 1;
            }
        }
        return -1.0; // invalid case
    }
};
