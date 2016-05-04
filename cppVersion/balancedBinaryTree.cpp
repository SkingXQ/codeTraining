/*
   link: https://leetcode.com/problems/balanced-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int r1 = treeDepth(root->left);
        int r2 = treeDepth(root->right);
        if(r1 == -1 || r2 == -1) return false;
        return abs(r1-r2)<=1? true: false;
    }
    
    int treeDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int r1 = 0;
        int r2 = 0;
        if(root->left != NULL) r1 = treeDepth(root->left);
        if(root->right != NULL) r2 = treeDepth(root->right);
        if(r1 == -1 || r2 == -1)  return -1;
        if(abs(r1-r2)>1) return -1;
        return r1>r2? r1+1: r2+1;
    }
};
