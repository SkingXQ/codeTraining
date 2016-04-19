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
// corect answer from another one
class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if(m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if(dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,dict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result; //memorize
        return result;
    }
};
