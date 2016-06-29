/*
    Link: https://leetcode.com/problems/valid-parentheses/
*/
class Solution {
private:
    map<char, char> parenth = {{'}', '{'}, {')', '('}, {']', '['}};
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        if(s.size() == 1) return false;;
        vector<char> st;
        for(auto i: s) {
            if(i == '(' || i == '{' || i == '[') st.push_back(i);
            else if(st.size()!=0 && st.back() == parenth[i]) st.pop_back();
            else st.push_back(i);
        }
        if(st.size()) return false;
        else return true;
    }
};
