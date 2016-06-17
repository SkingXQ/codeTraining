/*
    Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        combine(root, NULL);
    }
    
    void combine(TreeNode* l, TreeNode* r) {
        if(!l ) return;
        if(l->left == NULL && l->right == NULL) {
            l->right = r;
            combine(r, NULL);
        }else if(l->left != NULL && l->right == NULL) {
            combine(l->left, r);
            l->right = l->left;
            l->left = NULL;
            combine(r, NULL);
        }else if(l->left == NULL && l->right != NULL) {
            combine(l->right, r);
            combine(r, NULL);            
        }else {
            TreeNode* t = l->right;
            l->right = l->left;
            l->left = NULL;
            combine(l->right, t);
            combine(t, r);
        }
    }
};
