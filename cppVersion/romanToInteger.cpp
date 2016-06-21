/*
    Link: https://leetcode.com/problems/roman-to-integer/
    Tips: nothing special and just checking the the rule of roman numberal
*/

class Solution {
private:
    unordered_map<char, int> roman = {{'M', 1000}, {'D', 500}, {'L', 50}, {'V', 5}, {'C', 100}, {'X', 10}, {'I', 1}};
    unordered_set<char> romanMinus = {'C', 'X', 'I'};
public:
    int romanToInt(string s) {
        int result = 0;
        if(!s.size()) return result;
        for(int i=0; i<s.size(); i++) {
            result += roman[s[i]];
            if(romanMinus.count(s[i]) != 0 && i != s.size()-1) {
                if(roman[s[i]] < roman[s[i+1]]) 
                    result = result - 2 * roman[s[i]];
            }
        }
        return result;
    }
};
