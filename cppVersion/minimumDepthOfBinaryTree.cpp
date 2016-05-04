/* 
    link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    int depth;
public:
    int minDepth(TreeNode* root) {
        depth = 1;
        if(root ==NULL) return 0;
        DFS(root, 1);
        return depth;
    }
    void DFS(TreeNode* root, int depth_count){
        cout<<root->val<<endl;
        if(root->left == NULL && root->right == NULL){
            cout<<depth_count<<endl;
            if(depth == 1 || depth_count < depth)
                depth = depth_count;
        }else{
            if(root->left != NULL)
                DFS(root->left, depth_count+1);
            if(root->right != NULL)
                DFS(root->right, depth_count+1);
        }
    }
};
