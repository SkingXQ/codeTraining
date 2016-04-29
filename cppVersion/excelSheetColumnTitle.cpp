/*
    link: https://leetcode.com/problems/excel-sheet-column-title/
    tips: be careful 'Z' the same function as 0
*/
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        if(n==0) return result;
        while(n) {
            int i = n%26;
            if(i){
                result.insert(result.begin(), (char)(n%26-1+'A'));
                n /= 26;
            }else {
                result.insert(result.begin(), 'Z');
                n = n/26 -1;
            }
        }
        return result;
    }
};
