/*
    Link:  https://leetcode.com/problems/kth-smallest-element-in-a-bst/
    Solution: https://discuss.leetcode.com/topic/17573/4-lines-in-c
              https://discuss.leetcode.com/topic/17810/3-ways-implemented-in-java-binary-search-in-order-iterative-recursive
    Tips: It is beautiful solution. Actually using the inorder search. 
          We check the left tree to find whether the number of the nodes is containning the kth
          smallest one. And it will count the number of nodes.if not in left, and check root node and then
          right side.
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
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
   /* int find(TreeNode* root, int& k) {
        if (root) {
            int x = find(root->left, k);
            return !k ? x : !--k ? root->val : find(root->right, k);
        }
        return 0;
    }*/
    
    int find(TreeNode* root, int& k) {
        if(root) {
            cout<<k<<endl;
            int x = find(root->left, k);
            if(k == 0) return x;
            else {
                k--;
                if(!k) return root->val;
                else  return find(root->right, k);
            }
        }
        return 0;
    }
};
