/*
    Link:  https://leetcode.com/problems/basic-calculator-ii/
    Another Solution: https://leetcode.com/discuss/94523/simple-solution-beats-submissions-detailed-explanations
*/
#include<vector>
#include<deque>
#include<iostream>
#include<unordered_set>


using namespace std;

class Solution {
private:
    unordered_set<char> op = {'+', '-', '*', '/'};
public:
    int calculate(string s) {
        if(!s.size()) return  0;
        s += "-0";
        vector<int> nums;
        vector<char> ops;
        for(int i; i<s.size();) {
            if(s[i] == ' ') i++;
            else if(op.find(s[i]) == op.end()) {
                int c = 1;
                int n = int(s[i+1]-'0');
                while(n>=0 && n<=9) {
                    c++;
                    n = int(s[i+c]-'0');
                }
                nums.push_back(stoi(s.substr(i,c)));
                i += c;
            }else{
                if(!ops.size()) ops.push_back(s[i]);
                else {
                    char b = ops.back();
                    int se = nums.back();
                    nums.pop_back();
                    int f = nums.back();
                    nums.pop_back();
                    if(b == '/') {
                        nums.push_back(f/se);
                        ops.pop_back();
                        ops.push_back(s[i]);
                    } else if (b == '*') {
                        nums.push_back(f*se);
                        ops.pop_back();
                        ops.push_back(s[i]);
                    } else if (s[i] != '/' && s[i] != '*' && b == '-' ) {
                        ops.pop_back();
                        ops.push_back(s[i]);
                        nums.push_back(f-se);
                    } else if (s[i] != '/' && s[i] != '*' && b == '+' ) {
                        ops.pop_back();
                        ops.push_back(s[i]);
                        nums.push_back(f+se);
                    } else {
                        nums.push_back(f);
                        nums.push_back(se);
                        ops.push_back(s[i]);
                    }
                }
                i++;
            }
        }
        int result = nums[0];
        for(auto i=0; i < ops.size(); i++) {
            if(ops[i] == '-') result -= nums[i+1];
            else result += nums[i+1];
        }
        return result;
    }
};

int main() {
    Solution a;
    cout<<a.calculate("3+2*2");
    return 0;
}
