/*
    Link: https://leetcode.com/problems/single-number-iii/
    Discuss: https://leetcode.com/discuss/80755/share-my-c-solution
    Tips: see the comments
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num = 0;
        for(auto n : nums)
            num ^= n;
        cout<<num<<endl;
        
        int num1 = 0;
        int num2 = 0;
        int first = num & (~(num - 1)); // lowest bit int num
        // the bit of 1 means the two number is different here
        // use the first to divide the number into two heap
        // and the same number will be divided into same heap;
        for(auto n : nums){
            if((n & first)) num1 ^= n;
            else num2 ^= n;
        }
        
        return {num1, num2};
    }
};
