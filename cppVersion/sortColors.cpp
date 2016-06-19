
/*
    Link: https://leetcode.com/problems/sort-colors/
    Discuss: https://leetcode.com/discuss/104779/c-easy-o-n-solution  // same thoughts but different way to move, It use the backward to avoid swap between  0 and 2
    Tips: it similar with first missing number
          0 move the end of substring of 0's
          2 move to the begin og substring of 2's
          in the end It sorted.
	  Please remember some key points: over boundary and how to give the number of i.(i speend here 2 and half hours)
          I think I shoule have better ways to solve it.
          Please note that checking 2 mustb be ahead of checking 0. 
          Cause when you meet a 0, the number before  0, is 1, but the number after 2 is  1 or 0,
*/
#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(!nums.size() || nums.size() == 1) return;
        int zero = 0;
        for(; zero < nums.size(); zero++) {
            if(nums[zero] != 0) break;
        }
        int two = nums.size() - 1;
        for(; two > 0; two--) {
            if(nums[two] != 2) break;
        }
        for(int i=zero; i <= two;) {
            if(zero > nums.size()-1 || two < 0) return;
            if(nums[i] == 2) {
                int t = nums[two];
                nums[two] = 2;
                nums[i] = t;
                while(nums[two] == 2) {
                    two--;
                    if(two < 0) return;
                }
             }
            if(nums[i] == 0) {
                int t = nums[zero];
                nums[zero] = 0;
                nums[i] = t;
                while(nums[zero] == 0) {
                    zero++;
                    if(zero > nums.size()-1) return;
                }
                i = zero;
            }else{
                i++;
            }
        }
        for(auto n :nums)
            cout<<n<<" ";
        cout<<endl;
    }
};

int main()
{
    Solution a;
//    vector<int> b = {2,2,0,0,2,0,2,1,0};
    vector<int> c = {0,0,0,1,2,2,1,2,0,1};
  //  a.sortColors(b);
    a.sortColors(c);
    //a.sortColors(vector<int>{1,0});
    //a.sortColors(vector<int>{2,0});
}
