#include <iostream>
using namespace std;
int helper(vector<int>& nums, int i, int j, int minm)
{
    if (i==j)
        return 0;
    for (int k=i;k<=j-1;k++)
    {
        int steps=helper(nums, i,k)+helper(nums, k+1, j)+(nums[i]*nums[k]*nums[j]);
         minm=min(minm, steps);
    }
    return minm;
}
int matrixMultiplication(vector<int>& nums){
            int i=1,j=nums.size()-1;
            return helper(nums, i, j, INT_MAX);
    	}
int main() {
    vector<int> nums = {10, 15, 20, 25};
    cout<<matrixMultiplication(nums);
    return 0;
}
