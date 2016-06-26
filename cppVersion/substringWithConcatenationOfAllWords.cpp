#include <iostream>
#include <string>
#include <unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if((!s.size()) || (!words.size() || !words[0].size())) return res;
        int sw = words[0].size();
        unordered_multiset<string> hashWords(words.begin(), words.end());
        for(int i=0; i<=(int(s.size()-sw*words.size())); ) {
            if(hashWords.find(s.substr(i, sw)) != hashWords.end()) {
                cout<<*(hashWords.find(s.substr(i, sw)))<<endl;
                unordered_multiset<string> t(hashWords.begin(), hashWords.end());
                string st = s.substr(i, sw*words.size());
                /*  here will make a segment fault, I don't know why
                unordered_multiset<string> t = hashWords;
                cout<<*(hashWords.find(s.substr(i, sw)))<<endl;
                auto it = hashWords.find(s.substr(i, sw));
                t.erase(it);*/
                int r = searchWords(st, t, sw);
                if(r) {
                    res.push_back(i);
                    i += (sw * words.size());
                }else i++;
            }else{
                i++;
            }
        }
        return res;
    }
    
private:
    int searchWords(string& s, unordered_multiset<string>& hashWords, int sw) {
        if(s.size() < (sw * hashWords.size())) return 0;
        for(int i=0; i<s.size(); i += sw) {
            if(hashWords.find(s.substr(i, sw)) == hashWords.end()) return 0;
            else hashWords.erase(hashWords.find(s.substr(i, sw)));
        }
        return 1;
    }
};        

int main ()
{
    Solution t ;
    vector<string> a = {"word","good","best","good"};
    auto r = t.findSubstring("wordgoodgoodgoodbestword", a);
    for(auto i : r)
        cout<<i<<endl;
}
