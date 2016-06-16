/*
    Link:  https://leetcode.com/problems/rotate-list/
    Tips: It similar to the case which I met before.
          1. cut the list into half. You should name two variabls and a move one step and the another is twe step in each iteration.
          2. the same question as this one
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0)  return head;
        if(head == NULL) return head;
        int n = 1;
        int count = 1;
        ListNode* ahead = head;
        ListNode* behind = head;
        while(ahead->next != NULL)
        {
            ahead = ahead->next;
            if(n > k) {
                behind = behind->next;
                count++;
            }
            count++;
            n++;
            if(k > count && ahead->next == NULL) {
                k %= count;
                n = 1;
                ahead = head;
                behind = head;
                count = 1;
            }
        }
        if(count == k) return head;
        ahead->next = head;
        head = behind->next;
        behind->next = NULL;
        return head;
    }
};
