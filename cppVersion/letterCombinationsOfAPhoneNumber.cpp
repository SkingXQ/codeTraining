/*
    link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> keyboard = {"abc", "def", "ghi", \
                                   "jkl", "mno", "pqrs", \
                                   "tuv", "wxyz"};
        vector<string> result;
        if(digits == "") return result;
        for(auto i : digits){
            if(i == '0' || i == '*' || i == ' ' || i == '#'){
                return result;
            }
        } 
        result = DFS(digits, 0, keyboard);
        return result;
    }
    vector<string> DFS(string& digits, int begin, vector<string>& keyboard){
        vector<string> result;
        if(begin == digits.size()-1){
            for(int i = 0; i<keyboard[digits[begin]-'2'].size(); i++){
                result.push_back(keyboard[digits[begin]-'2'].substr(i, 1));
            }
            return result;
        }else{
            vector<string> temp = DFS(digits, begin+1, keyboard);
            for(int i = 0; i<keyboard[digits[begin]-'2'].size(); i++){
                string subdig = keyboard[digits[begin]-'2'].substr(i, 1);
                for(auto i : temp){
                    result.push_back(subdig + i);
                }
            }
            return result;
        }
        
    }
};
