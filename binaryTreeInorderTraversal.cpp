/** https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root != NULL) {
            vector<int> result1 = inorderTraversal(root->left);
            result.insert(result.end(), result1.begin(), result1.end());
            result.push_back(root->val);
            vector<int> result2 = inorderTraversal(root->right);
            result.insert(result.end(), result2.begin(), result2.end());
        }
        return result;
    }
};
