/*
    Link:  https://leetcode.com/problems/reverse-vowels-of-a-string/
    Discuss: https://leetcode.com/discuss/98987/java-standard-two-pointer-solution
    Tips: the vowels  in english is  a, e, i, o, u
*/

class Solution {
public:
    string reverseVowels(string s) {
        if(!s.size()) return s;
        int start = 0;
        int end = s.size()-1;
        unordered_set<char> charSet = {'a', 'e', 'i', 'o', 'u',
                                       'A', 'E', 'I', 'O', 'U'};
        while(start < end) {
            while(start<end && charSet.count(s[start])==0) {
                start++;
            }
            while(start<end && charSet.count(s[end])==0) {
                end--;
            }
            
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};
