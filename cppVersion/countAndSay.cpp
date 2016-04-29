/*
   link: https://leetcode.com/problems/count-and-say/
   solution: https://leetcode.com/discuss/81905/c-0ms-solution
*/

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        if( n == 1) return res;
        for(int i = 2; i <= n; i++) {
            int count = 1;
            string tmp = "";
            int j = 0;
            for(; j <res.size(); j++) {
                if(j != 0){
                    if(res[j] == res[j-1]) {
                        count++;
                    }else {
                        tmp.push_back((char)('0'+count));
                        tmp.push_back(res[j-1]);
                        count=1;
                    }
                }
            }
            tmp.push_back('0' + count);
            tmp.push_back(res[j-1]);
            res = tmp;
        }
        cout<<res<<endl;
        return res;
    }
};
