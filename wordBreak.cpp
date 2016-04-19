# coding=utf-8

/* Wrong answer
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        string temp = "";
        s += " ";
        backtracking("", temp, s, wordDict, result);
        return result;
    }
    
    bool checking(string splitStr, unordered_set<string>& wordDict){
        if(wordDict.count(splitStr)) return true;
        else return false;
    }
    
    void backtracking(string word, string splitStr, string s, unordered_set<string>& wordDict, vector<string>& result){
        splitStr += " ";
        splitStr += word;
        if(s == " "){
            result.push_back(splitStr.substr(2));
            return;
        }
        for(int i = 1; i < s.size(); i++){
            string word = s.substr(0, i);
            if(checking(word, wordDict)){
                    backtracking(word, splitStr, s.substr(i, s.size()), wordDict, result);
            }
        }
    }
};
*/
