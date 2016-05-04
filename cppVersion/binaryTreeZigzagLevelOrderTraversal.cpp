
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result={};
        map<int, vector<int>> temp;
        if(root ==  NULL) return result;
        iterate_tree(1, temp, root);
        for(auto t : temp){
            if((t.first)%2) result.push_back(t.second);
            else{
                vector<int> te;
                for(int i=t.second.size()-1; i >= 0; i--){
                    te.push_back(t.second[i]);
                }
                result.push_back(te);}
        }
        return result;
    }
    void iterate_tree(int flag, map<int, vector<int>>& t, TreeNode* tree){
        if(tree == NULL) return;
        if(t.size()<flag){
            vector<int> storage = {tree->val};
            t[flag] = storage;
        }else t[flag].push_back(tree->val);
        cout<<tree->val<<endl;
        iterate_tree(flag+1, t, tree->left);
        iterate_tree(flag+1, t, tree->right);
    }
};
