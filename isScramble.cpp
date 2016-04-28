# coding=utf-8

/*https://leetcode.com/problems/scramble-string/
    understanding the key of scramble:
        the word belong to a binary tree like abcd is not bdac
    key points:
        1 determin wheter the character in two strings
        2 beware of "" 
*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // stop iterator 
        if(s1 == s2) return true;

    // the trick to indicate whether the characters exists
    
        map<char, int> count;
        for(int i = 0; i < s1.size(); i++){
            count[s1[i]]++;
            count[s2[i]]--;
        }
        for(auto c : count){
            if(c.second != 0)
                return false;
        }
        int len = s1.length();

        for(int i=1; i <= len-1; i++){
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0, i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0, len-i)))
                return true;
        }
        // case abcd acdb
        return false;
    }
};
