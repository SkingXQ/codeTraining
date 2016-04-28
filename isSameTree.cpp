/**https://leetcode.com/problems/same-tree/
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
            return false;
        }
        if(p == NULL && q == NULL) {
            return true;}
        bool result1 = true, result2 = true;
        if(p->val == q->val) {
            result1 = isSameTree(p->left, q->left);
            result2 = isSameTree(p->right, q->right);
            return result1 && result2;
        }else {
            return false;
        }
        return true;
    }
};
