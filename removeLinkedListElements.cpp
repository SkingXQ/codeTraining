/**https://leetcode.com/problems/remove-linked-list-elements/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* t;
        t->val = 0;
        t->next = head;
        for(ListNode* i = t; i->next != NULL;) {
            if(i->next->val == val) {
                ListNode* j = i->next;
                i->next = i->next->next;
                delete j;
            }else{
                i = i->next;
            }
        }
        return t->next;
    }
};
