/*
    Link: https://leetcode.com/problems/sort-list/
    Tips: The key points are 1: using mergeSort 2: connect with each other instead of use space O(n)
*/

#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* result = listMergeSort(head, NULL);
        return result;
    }
    ListNode* listMergeSort(ListNode* head, ListNode* rear) {
        if(head == rear) return head;
        if(head->next == rear ) return head;
        ListNode* second = head;
        ListNode* first = head;
        while(second != rear && second->next != rear) {
            first = first->next;
            second =second->next->next;
        }   
        ListNode* t1 = listMergeSort(head, first);
        ListNode* t2 = listMergeSort(first, rear);
        head = listMerge(t1, first, t2, rear);
        return head;
    }
    ListNode* listMerge(ListNode* t1,ListNode* rear1, ListNode* t2, ListNode* rear) {
        ListNode* head1 = t1;
        ListNode* head2 = t2;
        ListNode* t = new ListNode(10000);
        while(t1 != rear1 && t2 != rear ) {
            if(t1->val >= t2->val) {
                t->next = t2;
                t = t->next;
                t2 = t2->next;
            } else {
                t->next = t1;
                t = t->next;
                t1 = t1->next;
            }
        }
        while(t1 != rear1) {
            t->next = t1;
            t = t->next;
            t1 = t1->next;
        }
        while(t2 != rear) {
            t->next = t2;
            t = t->next;
            t2 = t2->next;
        }
        t->next = rear;
        return  (head1->val)>=head2->val? head2: head1;
    }
};

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    //head->next->next->next = new ListNode(4);
    cout<<"solution"<<endl;
    Solution a;
    ListNode* t = a.sortList(head);

    while(t != NULL) {
        cout<<t->val<< " ";
        t = t->next;
    }
}
