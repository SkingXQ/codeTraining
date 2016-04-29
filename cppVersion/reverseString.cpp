/*https://leetcode.com/problems/reverse-string/
*/
class Solution {
public:
    string reverseString(string s) {
        if(s.size() == 0) return s;
        for(string::iterator start = s.begin(), end = s.end()-1; start < end; start++, end--) {
            swap(*start, *end);
        }
        return s;
    }
};
