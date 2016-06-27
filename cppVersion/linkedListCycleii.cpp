/*
    Link: https://leetcode.com/problems/linked-list-cycle-ii/
    Tips: check the solution of findTheDuplicateNumber.cpp.
          Checking the different of :
                second = head;
                first = first->next;// same motion

*/

#include<vector>
#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)  return NULL;
        ListNode* first = head;
        ListNode* second = head->next;
        while(second!=NULL && second->next!=NULL && first != second) {
            first = first->next;
            second = second->next->next;
        }
        if(second==NULL || second->next==NULL) return NULL;
        second = head;
        first = first->next;// same motion
        while(second->val != first->val) {
            first = first->next;
            second = second->next;
        }
        return first;
    }
};

int main() {
    ListNode* h = new ListNode(1);
    ListNode* s = new ListNode(2);
    h->next = s;
    ListNode* t = s;
    vector<int> p = {3,4,5,6,7};
    for(auto i: p){
        ListNode* l = new ListNode(i);
        t->next = l;
        t = t->next;
    }
    t->next = s;
    Solution a;
    cout<<(a.detectCycle(h))->val<<endl;
    return 0;
}
