// link: https://leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode* head) {
        int length = getlength(head);
        if(length == 0) return;
        ListNode* temp = reorderedList(head, length);
    }
    ListNode* reorderedList(ListNode* head, int length){
        if(length == 2){
            ListNode* t = head->next->next;
            head->next->next = NULL;
            return t;
        }
        if(length == 1){
            ListNode* temp = head->next;
            head->next = NULL;
            return temp;
        }
        ListNode* rec = reorderedList(head->next, length-2);
        ListNode* sto = head->next;
        head->next = rec;
        ListNode* rest = rec->next;
        rec->next = sto;
        return rest;
    }
    int getlength(ListNode* head){
        if(head == NULL) return 0;
        ListNode* pre = head;
        ListNode* next = head->next;
        int i = 1;
        while(next != NULL){
            i++;
            next = next->next;
        }
        return i;
    }
};
