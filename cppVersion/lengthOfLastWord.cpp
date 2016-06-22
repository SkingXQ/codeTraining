/*
    Link: https://leetcode.com/problems/length-of-last-word/
    Tips: the case : "aasda "  return 5.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(!s.size()) return 0;
        int result=0;
        string::iterator i;
        for(auto j=s.end()-1; j>=s.begin(); j--) {
            if(*j != ' ') {
                i = j;
                break;
            } 
        }
        for(; i>=s.begin(); i--) {
            if(*i != ' ') result++;
            else return result;
        }

        return result;
    }
};
