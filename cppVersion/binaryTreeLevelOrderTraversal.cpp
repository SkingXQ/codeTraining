/*
    Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
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
private:
    queue<TreeNode*> stackOfTreeNode;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        stackOfTreeNode.push(root);
        while(stackOfTreeNode.size()) {
            vector<int> tmpResult;
            queue<TreeNode*> tmp;
            TreeNode* t = stackOfTreeNode.front();
            stackOfTreeNode.pop();
            while(t) {
                tmpResult.push_back(t->val);
                if(t->left) tmp.push(t->left);
                if(t->right) tmp.push(t->right);
                if(stackOfTreeNode.size()) {
                    t = stackOfTreeNode.front();
                    stackOfTreeNode.pop();
                } else  t = NULL;
            }
            result.push_back(tmpResult);
            stackOfTreeNode = tmp;
        }
        
        return result;
    }
};

