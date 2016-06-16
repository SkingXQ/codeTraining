/*
    Link: https://leetcode.com/problems/count-complete-tree-nodes/
    Solution: https://leetcode.com/discuss/99027/80ms-simple-c-recurrence-solution-%EF%BC%8Ceasy-to-understand    second comments
    Tips: In very beginning I use nest way to solve but over time limits;
          After read the discuss, I realize that I should use the feature of the complete binary tree.
          Just add the complete child tree and iterate it  till figure out the incomplete leaf.
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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lLevel = 0;
        TreeNode* t = root;
        while(t) {
            lLevel++;
            t = t->left;
        }
        int result = 0;
        while(root) {
            TreeNode* tmp = root->left;
            int rLevel = 1;
            while(tmp){
                rLevel++;
                tmp = tmp->right;
            }
            if(rLevel != lLevel) {
                result += (1<<(rLevel-1));
                root = root->left;
            }else{
                result += (1<<(rLevel-1));
                root = root->right;
            }
            lLevel--;
        }        
        
        return result;
    }
};
