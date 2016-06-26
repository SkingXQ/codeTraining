/*
    Link: https://leetcode.com/problems/different-ways-to-add-parentheses/
    Tips: I saw the tags of this question showed "diveide and conquer". So I feel I need to 
	  divide the string in the operator. After recursion, Add the result.
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if(!input.size()) return res;
        int s = input.size();
        for(int i=0; i<input.size(); i++) {
            int n = int(input[i]-'0');
            if(n>=0 && n<= 9) continue;
            else{
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1, s-i-1));
                combine(res, left, right, input[i]);
            }
        }
        if(res.size() == 0) {
            res.push_back(stoi(input));
        }
        sort(res.begin(), res.end());
        return res;
    }

private:
    void combine(vector<int>& res, vector<int>& left, vector<int>& right, char op) {
        for(auto l : left) {
            for(auto r : right) {
                if(op == '*') res.push_back(r*l);
                else if(op == '-') res.push_back(l-r);
                else if(op == '+') res.push_back(l+r);
            }
        }
    }
};
