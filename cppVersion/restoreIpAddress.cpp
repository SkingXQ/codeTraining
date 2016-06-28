/*
    Link: https://leetcode.com/problems/restore-ip-addresses/
    Tips: so many situation.
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(!s.size()) return res;
        int dot = 3;
        return divideString(s, dot);
    }
    
    vector<string>  divideString(string s, int dot) {
        if(dot == 0 && s.size() > 10) return {};
        else if(dot == 0 && stol(s) <= 255 && s.size() > 1 && s[0] == '0') return {}; 
        else if(dot == 0 && stol(s)<= 255) return {s};
        int i = 1;
        int si = s.size();
        vector<string> res;
        for(; i<s.size(); i++){
            if(stoi(s.substr(0, i)) > 255) break;
            else if(i!=1 && s[0] == '0') break;
            else if(stoi(s.substr(0, i)) <= 255) {
                vector<string> ts = divideString(s.substr(i, si-i), dot-1);
                for(auto t : ts) {
                    res.push_back(s.substr(0, i) + "." + t);
                }
            }
        }
        return res;
    }
};
