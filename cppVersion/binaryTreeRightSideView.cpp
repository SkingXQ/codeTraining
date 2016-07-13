/*
    Link:https://leetcode.com/problems/binary-tree-right-side-view/
    Tips: BFS
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> stack;
        if(!root) return result;
        stack.push_back(root->right);
        stack.push_back(root->left);
        result.push_back(root->val);
        while(stack.size() != 0) {
            vector<TreeNode*> t;
            for(auto s: stack) {
                if(s) {
                    cout<<s->val<<endl;
                    result.push_back(s->val);
                    break;
                }
            }
            for(auto s: stack) {
                if(s) {
                    t.push_back(s->right);
                    t.push_back(s->left);
                }
            }
            stack = t;
        }
        return result;
    }
    
};
