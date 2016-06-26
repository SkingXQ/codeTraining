/*
    Link: https://leetcode.com/problems/odd-even-linked-list/
    Tips: be cafeful breaking the loop of results
*/

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* backup = even;
        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        if(even) even->next = NULL;
        odd->next = backup;
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    vector<int> p = {2,3,4,5,6};
    for(auto i : p) {
        t->next = new ListNode(i);
        t = t->next;
    }
    Solution a;
    a.oddEvenList(head);
    while(head) {
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}

