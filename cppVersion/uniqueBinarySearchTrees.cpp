/*
    link: https://leetcode.com/problems/unique-binary-search-trees-ii/
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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>{};
        vector<TreeNode*> result = iterate_Tree(1, n);
        return result;
    }
    
    vector<TreeNode*> iterate_Tree(int start, int end){
        vector<TreeNode*> result;
        if(start > end) return vector<TreeNode*>{nullptr};
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left = iterate_Tree(start, i-1);
            vector<TreeNode*> right = iterate_Tree(i+1, end);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* p = new TreeNode(i);// allocate the heap space for tree
                    p->left = l;
                    p->right = r;
                    result.push_back(p);
                }
            }
        }
        return result;
    }
    
    /*void display_tree(TreeNode* n){
        if(n != NULL){
            cout<<n->val<<endl;
            display_tree(n->left);
            display_tree(n->right);
        }else{
            cout<< "NULL"<<endl;
        }
    }*/
};
