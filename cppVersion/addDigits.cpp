/*
    link: https://leetcode.com/problems/add-digits/
    tips:
         according to the questions, given the number is 38, when we do the first step ,it measns remove 
        30*9/10 = 27. the second step remove the 9, in the end ,we ask for the rest after divied by 9.
         be careful the num % 9==0 ornum== 0
*/
class Solution {
public:
    int addDigits(int num) {
        if(num%9 == 0 && num!=0)
            return 9;
        return (num%9);
    }
};
