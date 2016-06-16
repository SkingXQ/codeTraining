/*
    Link: https://leetcode.com/problems/valid-anagram/
    Tip: turn string into the list of characters
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> dict(52, 0);
        for(auto i=s.begin(); i != s.end(); i++)
            dict[*i - 'a'] += 1;
        for(auto j=t.begin(); j!=t.end(); j++)
            dict[*j - 'a'] -= 1;
            
        for(auto k=dict.begin(); k!=dict.end(); k++){
            if(*k != 0)
                return false;
        }
        return true;
    }
};
