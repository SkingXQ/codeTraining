/*
    Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
    Tip: I use two method to tracker the medium node 1, add  a guard ; 2, temperary pointer point to pre node before later one;
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)  return NULL;
        TreeNode* root = new TreeNode(0);
        if(!head->next) {
            root->val = head->val;
            return root;
        }
        ListNode* pre = new ListNode(INT_MAX);
        ListNode* t = pre;
        pre->next = head;
        ListNode* suf = head;
        while(suf && suf->next) {
            pre = pre->next;
            suf = suf->next;
            suf = suf->next;
        }
        root->val = pre->next->val;
        convertRightBST(pre->next->next, root);
        pre->next = NULL;
        convertLeftBST(head, root);
        delete t;
        return root;
    }
    
private: 
    void convertLeftBST(ListNode* head, TreeNode* root) {
        if(!head)  return;
        TreeNode* left = new TreeNode(0);
        root->left = left;
        if(!head->next) {
            left->val = head->val;
            return ;
        } 
        ListNode* pre = head;
        ListNode* suf = head;
        ListNode* t = NULL;
        while(suf && suf->next) {
            t = pre;
            pre = pre->next;
            suf = suf->next;
            suf = suf->next;
        }
        left->val = pre->val;
        t->next = NULL;
        convertLeftBST(head, left);
        convertRightBST(pre->next, left);
    }
    
    void convertRightBST(ListNode* head, TreeNode* root) {
        if(!head)  return;
        TreeNode* right = new TreeNode(0);
        root->right = right;
        if(!head->next) {
            right->val = head->val;
            return ;
        } 
        ListNode* pre = head;
        ListNode* suf = head;
        ListNode* t = NULL;
        while(suf && suf->next) {
            t = pre;
            pre = pre->next;
            suf = suf->next;
            suf = suf->next;
        }
        right->val = pre->val;
        t->next = NULL;
        convertLeftBST(head, right);
        convertRightBST(pre->next, right);        
    }
};
