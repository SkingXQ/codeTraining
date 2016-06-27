/*
    Link: https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) l1==NULL? l2: l1;
        ListNode* result = addList(l1, l2);
        return result->next;
    }
    
    ListNode* addList(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(INT_MAX);
        ListNode* b = head;
        int c = 0;
        while(l1!=NULL && l2!=NULL){
            int n = (l1->val) + (l2->val) + c;
            b->next = new ListNode(n%10);
            c = n / 10;
            l1 = l1->next;
            l2 = l2->next;
            b = b->next;
        }
        while(l1!=NULL){
            int n = (l1->val) + c;
            b->next = new ListNode(n % 10);
            c = n / 10;
            l1 = l1->next;
            b = b->next;
        }
        while(l2!=NULL){
            int n = (l2->val) + c;
            b->next = new ListNode(n % 10);
            c = n / 10;
            l2 = l2->next;
            b = b->next;
        }
        if(c) {
            b->next = new ListNode(1);
        }
        return head;
    }
};
