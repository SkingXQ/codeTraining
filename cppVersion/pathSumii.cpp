/*
    link: https://leetcode.com/problems/path-sum-ii/
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> r = pathSearch(root);
        vector<vector<int>> result;
        for(auto i=r.begin(); i!=r.end(); i++) {
            int re = 0;
            for(auto j=i->begin(); j!=i->end(); j++)
                re += *j;
            if(re == sum)
                result.push_back(*i);
        }
        return result;
    }
    
    vector<vector<int>> pathSearch(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)  return result;
        vector<vector<int>> left = pathSearch(root->left);
        vector<vector<int>> right = pathSearch(root->right);
        if(left.size()==0 && right.size() == 0){
            result.push_back(vector<int>{root->val});
        }
        for(auto i=left.begin(); i!=left.end();i++){
            i->insert(i->begin(), root->val);
            result.push_back(*i);
        }
        for(auto i=right.begin(); i!=right.end();i++){
            i->insert(i->begin(), root->val);
            result.push_back(*i);
        } 
        return result;
    }
};
