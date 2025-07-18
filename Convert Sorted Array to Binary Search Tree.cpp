class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size()==0)
        return nullptr;
        return binarySearch(0, nums.size()-1, nums);
    }
    TreeNode* binarySearch(int start, int end, vector<int> &nums)
    {
       if (start>end)
            return nullptr;
        int mid=start+(end-start)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=binarySearch(start, mid-1, nums);
        node->right=binarySearch(mid+1, end, nums);
        return node;
    }
};
