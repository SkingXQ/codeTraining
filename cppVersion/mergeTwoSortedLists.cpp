/*
    Link: https://leetcode.com/problems/merge-two-sorted-lists/
    Tips: I think the program I code is ugly. I will check other person's work to learn something
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL) return l1 == NULL?l2: l1;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* head = new ListNode(INT_MAX);
        while(head1 != NULL && head2 != NULL) {
            if(head1->val >= head2->val) { 
                head->next = head2;
                head = head->next;
                head2 = head2->next;
            }else {
                head->next = head1;
                head = head->next;
                head1 = head1->next;
            }
        }
        while(head1 != NULL) {
            head->next = head1;
            head = head->next;
            head1 = head1->next;
        }
        while(head2 != NULL) {
            head->next = head2;
            head = head->next;
            head2 = head2->next;
        }        
        head->next = NULL;
        return l1->val >= l2->val? l2: l1;
    }
};
