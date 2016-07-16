/*
    Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
    Solution:https://discuss.leetcode.com/topic/16797/very-concise-o-log-min-m-n-iterative-solution-with-detailed-explanation
    Tips: It is easy to understand we could solve it recursive to do that we cancompare the left part and the right part 
         seperately and remove from the sequence till we find the key.
         But I fail to code it.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() && !nums2.size()) {
            int s = nums1.size();
            return s%2?  double(nums1[s/2]): (double(nums1[s/2]) + double(nums1[s/2-1])) / 2;
        } 
        int b1 = 0;
        int b2 = 0;
        int e1 = nums1.size()-1;
        int e2 = nums2.size()-1;
        cout<<"size"<<e1<< " "<<e2<<endl; 
        while((e1-b1+e2-b2+2)>2) {
            cout<<"hiwle"<<e1<<" "<<e2<<" "<<b1<<" "<<b2<<endl;
            int s1 = (e1-b1+1)/2-1;
            int s2 = (e2-b2+1)/2-1;
            s1 = (s1>=0?s1; 0);
            s2 = (s2>=0?s2; 0);
            cout<<s1<<"     "<<s2<<endl;
            if(nums1[b1+s1] > nums2[b2+s2]){
                b2 = b2+s2+1;
                cout<<"f11 "<<b2<<endl;
            }else {
                b1 = b1+s1+1;
                cout<<b1<<endl;
};
            if(nums1[e1-s1] > nums2[e2-s1])
                e1 = e1-s1-1;
            else
                e2 = e2-s2-1; 
        }
        if((nums1.size()+nums2.size())%2) return nums1[e1]>nums2[e2]? double(nums1[e1]): double(nums2[e2]);
        else return (double(nums1[e1]) + double(nums2[e2]))/2;

        return 1.0;
    }
};

int main() {
    Solution b;
    vector<int> n1 = {1,2};
    vector<int> n2 = {3};
    cout<<b.findMedianSortedArrays(n1, n2)<<endl;
    return 0;
}
