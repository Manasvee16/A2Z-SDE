/* 1. Preorder + Inorder
Preorder gives the root first.
Inorder tells us left and right subtree structure.
Combining both, we can recursively build the exact tree.
✅ Always gives a unique tree.

2. Postorder + Inorder
Postorder gives the root last.
Inorder gives left and right subtree structure.
Combining both, we can recursively build the exact tree.
✅ Always gives a unique tree.

3. Preorder + Postorder
Preorder gives root first, Postorder gives root last.
But without Inorder, we cannot know which nodes go to left or right.
Multiple different trees can produce the same preorder and postorder.
❌ Does NOT give a unique tree (unless additional constraints like "full binary tree").

4. Inorder + Inorder OR Preorder + Preorder OR Postorder + Postorder
Just one traversal repeated → definitely not enough.
❌ Cannot construct unique tree.*/

class Solution {
  public:
    bool isPossible(int a, int b) {
        // code here
        if ((a==1 && b==2) || (a==2 && b==1))
            return true;
        if ((a==3 && b==2) || (a==2 && b==3))
            return true;
        return false;
    }
};
