/*
    Link: https://leetcode.com/problems/next-permutation/
    Solution:https://discuss.leetcode.com/topic/19264/1-4-11-lines-c
    TIPS:I fall into a hole that I couldn't think in another ways;
            I thought it's similar with reverse wors sequence in a string.
*/

#include<vector>
#include<iostream>

using namespace std;
class Solution{

    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, k = i;
        while (i > 0 && nums[i-1] >= nums[i])
            i--;
        for (int j=i; j<k; j++, k--)
            swap(nums[j], nums[k]);
        if (i > 0) {
            k = i--;
            while (nums[k] <= nums[i])
                k++;
            swap(nums[i], nums[k]);
    }
}
};
/*
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(!nums.size()) return;
        int head = -1;
        for(int i=nums.size()-1; i>0; i--) {
            if(nums[i] > nums[i-1]) {
                head = i-1;
                break;
            }   
        }   
        int tail = nums.size()-1;
        int point = head++; 
        if(head) {
            while(tail >= head) {
                if(nums[head] > nums[point] && nums[tail] > nums[point]) {
                    int b = nums[point];
                    nums[point] = nums[tail];
                    nums[tail--] = nums[head];
                    nums[head++] = b;
                    break;
                }else if(tail == head) {
                    int b = nums[tail];
                    nums[tail--] =  nums[point];
                    nums[point] = b;
                }else if(nums[head] < nums[point] && nums[tail] < nums[point]) {
                    int b = nums[point];
                    nums[point] = nums[tail+1];
                    nums[tail+1] = b;
                    break;
                }else{
                    int b = nums[tail];
                    nums[tail--] = nums[head];
                    nums[head++] = b;
                }
            }
            while(tail >= head) {
                int b = nums[tail];
                nums[tail--] = nums[head];
                nums[head++] = b;
            }
        }else {
            while(tail >= head) {
                int b = nums[tail];
                nums[tail--] = nums[head];
                nums[head++] = b;
            }
        }
    }   
};
*/
int main(){
    Solution b ;
    vector<int> t ={1,4,6,5,3};
    b.nextPermutation(t);
    return 1;
}
