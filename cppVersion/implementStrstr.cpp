/*
    Link: https://leetcode.com/problems/implement-strstr/
    Tips: check the key point.
*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<unordered_set<int>> restore;
        if(!needle.size()) return 0;
        else if(!haystack.size()) return -1;
        else if(needle.size() > haystack.size()) return -1;
        for(int j=0; j != haystack.size(); j++) {
            if(j+needle.size() > haystack.size()) break;// case: "aaaa(n*a)aaaa"and "aaaa(n*a)aaab"
            for(int i=0; i < needle.size(); i++) {
                if(haystack[j + i] != needle[i])
                    break;
                if(i == needle.size() - 1) {
                    return j;//find the first one and return 
                }
            }
        }
        return -1;
    }
};
