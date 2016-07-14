/*
    Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
        if(!head) return head;
        ListNode* s = head;
        while(s && s->next) {
            if(s->val == s->next->val) {
                s->next = s->next->next;
            }else {
                s = s->next;
            }
        }
        return head;
    }
};
