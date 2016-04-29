/*
 link https://leetcode.com/problems/distinct-subsequences/
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> f(t.size()+1, 0);
        f[0] = 1;
        for(int i = 0; i<s.size(); i++){
            for(int j = t.size()-1; j>=0; j--){
                int temp = s[i] == t[j]?f[j]:0;
                f[j+1] += temp;
                //f[j + 1] += s[i] == t[j] ? f[j] : 0;
            }
        }
        return f[t.size()];
        /*
        延长s的子串，从最开始的开始，扫描在t上的位置，并且做记录
        特殊情况：如果是tsadadt这种类型情况，s出现字符t，那么只会对碰见最近的t近路
        并且最开始的t也会被记录，但是不影响后面的使用，也就是状态离得太远了
        2 如果是tete，这种的s，那么因为字符串够长，能够将影响传递到后面。
        */
    }
};
