/*
    Link: https://leetcode.com/problems/validate-binary-search-tree/
    Tips: BST(breath search tree),
          with the list help, I check the child tree is valid or not and check the max in the left sid and min in the right side.
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
    bool isValidBST(TreeNode* root) {
        list<int> l;
        return isValidBST(root, l);
    }
    
    bool isValidBST(TreeNode* root, list<int>& l) {
        if(root == NULL) return true;
        list<int> l1;
        list<int> l2;
        if(isValidBST(root->left, l1) && isValidBST(root->right, l2)) {
            if(root->left == NULL && root->right == NULL) {
                l.push_back(root->val);
                return true;
            }else if(root->left == NULL && l2.front() > root->val) {
                l.push_back(root->val);
                l.merge(l2);
                return true;
            }else if (root->right == NULL && l1.back() < root->val) {
                l.merge(l1);
                l.push_back(root->val);
                return true;
            }else if(l1.back() < root->val && l2.front() > root->val) {
                l.merge(l1);
                l.push_back(root->val);
                l.merge(l2);
                return true;
            }
        }
        return false;
    }
};
