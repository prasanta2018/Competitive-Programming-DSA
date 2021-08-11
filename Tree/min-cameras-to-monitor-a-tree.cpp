// LeetCode

Q: Given a binary tree, we install cameras on the nodes of the tree. Each camera at a node can monitor its parent, itself, and its immediate children. Calculate the minimum number of cameras needed to monitor all nodes of the tree.

POINTS TO BE REMEMBER:
======================
1. Since we want to minimize the number of cameras, one thing is clear we don't place cameras at the leaf node. So we can trace from leaf to root.
2. This makes DFS the most likely choice to address the problem.
3. If the current node is a leaf node we don't need camera. IFf(root-> left == NULL && root->right == NULL) then return -1]
4. If we don't have a camera on the current node then parent needs it.
5. If the current node has a camera then its parent does not need a camera

We can assign different values to indicate those state.
-1 from children means to put a camera on current node and 1 from any children means no camera on current node.

Conditions:
-----------
Suppose, I'm on a node and checking the children of its.
IF(l == -1 | r == -1): that means atleast one of the child is not covered by camera. So, we need to place a camera on the current node and return 1 to parent since parent does not require the camera.

IF(l == 1 | r == 1): that means left or right child atleast one should have camera, So, no need to place camera on current node and return 0.

IF(l == 0 and r == 0): that means child of child of the current node has camera, so we should place a camera on the current node.


Trurth Table for all possible combinations:
-------------------------------------------
[l]    [r]  [Result]    [return]

-1      X    count++      1
 X     -1    count++      1
 1     0/1     -          0
0/1     1      -          0
 0      0    count++     -1

Intersting Testcase: [0,0,null,null,0,0,null,null,0,0] = 2

*/
class Solution {
public:
    int count = 0;
    int minCameraCoverUtil(TreeNode* root) {
        int l = 0, r = 0;
        if(root-> left == NULL && root->right == NULL)
            return -1;
        if(root->left)
            l = minCameraCoverUtil(root->left);
        if(root->right)
            r = minCameraCoverUtil(root->right);
        if(l == -1 || r == -1) {
            count++;
            return 1;
        }
        if(l == 1 || r == 1)
            return 0;
        else
            return -1;
    }

    int minCameraCover(TreeNode* root) {
        int result = 0;
        result = minCameraCoverUtil(root);
        if(result == -1)
            count++;
        return count;
    }
};