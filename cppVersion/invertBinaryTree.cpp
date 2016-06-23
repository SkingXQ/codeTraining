/*
    Link: https://leetcode.com/problems/invert-binary-tree/
    Tips: a nice drama :)

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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)  return root;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        TreeNode* t = root->right;
        root->right = root->left;
        root->left = t;
        return root;
    }
};
