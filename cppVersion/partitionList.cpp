/*
    link; https://leetcode.com/problems/partition-list/
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        ListNode* less = NULL;
        ListNode* lessTail = NULL;
        ListNode* great = NULL;
        ListNode* greatTail = NULL;
        for(ListNode* i = head; i != NULL;) {
            if(i->val < x) {
                if(less == NULL) {
                    less = i;
                    lessTail = i;
                }else {
                    lessTail->next = i;
                    lessTail = i;
                }
            }else {
                if(great == NULL) {
                    great = i;
                    greatTail = i;
                }else {
                    greatTail->next = i;
                    greatTail = i;
                }                
            }
            i = i->next;
        }
        if(less != NULL && great != NULL) {
        lessTail->next = great;
        greatTail->next = NULL;
        }else if(less == NULL){
            less = great;
            greatTail->next = NULL;
        }else if(great == NULL) {
            lessTail->next = NULL;
        }
            
        return less;
    }
};
