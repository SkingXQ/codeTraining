/*
    Link: https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* t = head->next;
        head->next = NULL;
        while(t) {
            ListNode* b = head;
            head = t;
            t = t->next;
            head->next = b;
        }
        
        return head;
    }
};
