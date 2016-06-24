/*
    Link: https://leetcode.com/problems/fraction-to-recurring-decimal/
    Discuss: https://leetcode.com/discuss/42159/0ms-c-solution-with-detailed-explanations
    Tips: I have thought that the numerator mutiply some 10^n to get the number
          But the discuss is more clearer. Wonderful.
	  I should read the string operation once again.
          Good method,.
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string res;
        if((numerator<0) ^ (denominator<0)) res += "-";
        long num = numerator<0? long(numerator) * (-1): long(numerator);
        long den = denominator<0? long(denominator)*(-1): long(denominator);
        long integral = num / den;
        cout<<num<<" "<<den<<endl;
        res += to_string(integral);
        long rest = num % den;
        if(!rest) return res;
        res += ".";
        unordered_map<long, long> md;// great thoughts
        md[rest] = res.size();
        rest *= 10;
        while(rest) {
            cout<<res<<endl;
            int i = rest / den;
            if(md.find(rest) != md.end()){
                res.insert(md[rest], 1, '(');//string& insert (size_t pos,   size_t n, char c)
                res += ")";
                break;
            }
            md[rest] = res.size();
            res += to_string(i);
            rest = (rest % den) * 10;// the position of the equaltion is important.
        }
        return res;
    }
};
