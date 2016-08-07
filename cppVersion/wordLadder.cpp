/*
    Link: https://leetcode.com/problems/word-ladder/
    Solution: https://discuss.leetcode.com/topic/16983/easy-76ms-c-solution-using-bfs
*/
#include<string>
#include<unordered_set>
#include<vector>
#include<iostream>

using namespace std;


/*
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.insert(endWord);
        queue<string> toVisit;
        addNextWords(beginWord, wordDict, toVisit);
        int dist = 2;
        while (!toVisit.empty()) {
            int num = toVisit.size();
            for (int i = 0; i < num; i++) {
                string word = toVisit.front();
                toVisit.pop();
                if (word == endWord) return dist;
                addNextWords(word, wordDict, toVisit);
            }
            dist++;
        }
        return 0;
    }
    
private:
    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        wordDict.erase(word);
        for (int p = 0; p < (int)word.length(); p++) { // nice way to limit the O(logN) , my method is O(n)
            char letter = word[p];
            for (int k = 0; k < 26; k++) { 
                word[p] = 'a' + k;
                if (wordDict.find(word) != wordDict.end()) {
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[p] = letter;
        } 
    } 
};

*/
// time limit over
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        vector<string> wordLadder;
        wordLadder.push_back(beginWord);
        wordList.insert(endWord);
        int count = 1;
        while(wordList.count(endWord) == 1 && wordLadder.size() != 0) {
            BFS(wordLadder, wordList);
            count++;
        }
        if(wordList.count(endWord) == 0) return count;
        else return 0;
    }
    
private:
    void BFS(vector<string>& wordLadder, unordered_set<string>& wordList) {
        vector<string> wl;
        for(auto i=wordLadder.begin(); i != wordLadder.end(); ++i) {
            string word = *i;
            unordered_set<string> t(wordList.begin(), wordList.end());
            for(auto w : wordList) {
                if(check(word, w)) {
                    wl.push_back(w);
                    t.erase(w);
                }
            }
            wordList = t;
        }
        wordLadder = wl;
    }
    
    bool check(string a, string b) {
        int count = 0;
        for(int i=0; i< a.size(); ++i) {
            if(a[i] != b[i]) count++;
        }
        return count == 1? true: false;
    }
};


int main() {
    string b = "hit";
    string e = "cog";
    unordered_set<string> l = {"hot", "dot", "dog", "lot", "log"};
    Solution t;
    cout<<t.ladderLength(b, e, l)<<endl;
    return 0;
}
