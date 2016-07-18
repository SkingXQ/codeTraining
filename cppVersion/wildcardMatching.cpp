/*
    Link: https://leetcode.com/problems/wildcard-matching/
    Discuss: https://discuss.leetcode.com/topic/17901/accepted-c-dp-solution-with-a-trick
    Tips: I use the wrong method to solve it .
          With DP, I shall think it as a  matrix which the column is p.siz + 1. and row is s.size +1;
          The most diffcult way is the p begin with * or not.
          and the row of 0 and column of 0 is hard to comfirm/

*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*
class Solution {
public:
    bool isMatch(string s, string p) {
        int s1 = s.size();
        int s2 = p.size();
        if(!s.size() && !p.size()) return true;
        if(s.size() && !p.size()) return false;
        int i = 0;  
        for(; i<s2; ) {
            cout<<p[i]<<endl;
            if(p[i] == '*') {
                for(int j=i; j<=s1; j++) {
                    if(isMatch(s.substr(j), p.substr(i+1))){
                        cout<<s.substr(j)<< " "<<p.substr(i+1)<<endl;
                        return true;
                    }
                }
                break;
            }else {
                if(i > s1-1) return false;
                if(p[i] == '?') i++;
                else if(p[i] == s[i]) i++;
                else if(p[i] != s[i]) return false;
            }     
        }
        if(i < s1 || i < s2) return false; 
        cout<<i<<endl;
        return true;
    }
};*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int s1 = s.size() + 1;
        int s2 = p.size() + 1;
        vector<bool> cur(s1, false);
        cur[0] = true;
        for(int i=1; i < s2; i++) {
            bool pre = cur[0];
            cur[0] = cur[0] && p[i-1] == '*';
            for(int j=1; j < s1; j++) {
                bool t = cur[j];
                if(p[i-1] != '*') 
                    cur[j] = pre && (p[i-1] == s[j-1] || p[i-1] == '?');
                else
                    cur[j] = cur[j-1] || cur[j];
                pre = t;  
            }
        } 
        for(auto i: cur)
                cout<<i<<endl;
        cout<<"sad"<<endl;
        return cur[s1-1];
    }
};

int main() {
    Solution t;
    string t1 = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    string t2 = "a*******ba";

    cout<< t.isMatch(t1, t2)<<endl;

}
