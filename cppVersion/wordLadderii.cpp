/*
   Link: https://leetcode.com/problems/word-ladder-ii/
   Solution:  https://discuss.leetcode.com/topic/16826/88ms-accepted-c-solution-with-two-end-bfs-68ms-for-word-ladder-and-88ms-for-word-ladder-ii
   Tips: http://blog.csdn.net/fengart/article/details/2480774
*/
#include<iostream>
#include<queue>
#include<unordered_set>
#include<vector>
#include<string>
 
using namespace std;
// time limitation
class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > ret ;
        vector<string> b = {beginWord};
        ret.push_back(b);
        while(addNextWord(endWord, wordList, ret) && ret.size());
        return ret;
    }

private:
    bool addNextWord(string& endWord, unordered_set<string>& wordList, vector<vector<string>>& ret) {
        if(addEndWord(endWord, ret)) return false;
        vector<vector<string>> tmp = {};
        for(auto i=ret.begin(); i != ret.end(); ++i) {
            string t = i->back();
            for(int j=0; j<t.length(); ++j) {
                string tt = t;
                for(int c=0; c<26; ++c) {
                    tt[j] = (char) c+'a';
                    if(wordList.count(tt) != 0) {
                        vector<string> ttt = *i;
                        ttt.push_back(tt);
                        tmp.push_back(ttt);
                    }
                }
            }
        }
        ret = tmp;
        for(auto r: ret)
            wordList.erase(r.back());
        return true;
    }

    bool addEndWord(string& endWord, vector<vector<string>>& ret) {
        bool f = false;
        vector<vector<string>> tmp = {};
        for(int i=0; i < ret.size(); ++i) {
            string word = ret[i].back();
            for(int j=0; j<word.length(); ++j) {
                string t = word;
                for(int c=0; c<26; ++c) {
                    word[j] = (char) c+'a';
                    if(word == endWord) {
                        ret[i].push_back(endWord);
                        tmp.push_back(ret[i]);
                        f = true;
                    }
                    word = t;
                }
            }
        }
        if(f) ret = tmp;
        return f;
    }
};
 

int main() {
    unordered_set<string> wl = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
    string b = "red";
    string e = "tax";
    Solution t;
    vector<vector<string> > r = t.findLadders(b, e, wl);
    cout<<r.size()<<endl;
    for(int i = 0; i < r.size(); i++) {
        for(int I=0; I < r[i].size(); I++)
            cout<<r[i][I]<<" ";
        cout<<endl;
    }
    return 0;
}
