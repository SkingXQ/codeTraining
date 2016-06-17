/*
    Linked: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    Tips: add a watcher and becareful the out of segment for the conditions don't match;
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
        ListNode* pre = new ListNode(INT_MAX);
        pre->next = head;
        ListNode* suf = head;
        head = pre;
        while(suf && suf->next && suf != NULL) {
            while(suf->next && pre->next->val == suf->next->val ) {
                suf = suf->next;
            }
            if(pre->next != suf) {
                pre->next = suf->next;
                suf = suf->next;
            }else {
                pre = suf;
                suf = suf->next;
            }
        }
        return head->next;
    }
};
