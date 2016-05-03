/*
    link: https://leetcode.com/problems/multiply-strings/
    solution:  https://leetcode.com/discuss/26602/brief-c-solution-using-only-strings-and-without-reversal
    tip:
         1 how to control the carrie;
         2 the position determine
         3 string.find_first_not_of('0')

*/
class Solution {
public:
    string multiply(string num1, string num2) {
        string result(num1.size()+num2.size(), '0');
        for(int i=num1.size()-1; i>=0; i--) {
            int carry = 0;
            for(int j=num2.size()-1; j>=0; j--) {
                int r = (num1[i]-'0') * (num2[j]-'0') + carry + result[i+j+1] - '0';
                result[i+j+1] = (r % 10) + '0';
                carry = r / 10;
            }
            result[i] += carry;
        }
        size_t pos = result.find_first_not_of('0');
        while(string::npos != pos) 
            return result.substr(pos);
        return "0";
    }
};
