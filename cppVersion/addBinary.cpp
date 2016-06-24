/*
    Link: https://leetcode.com/problems/add-binary/
    Tips: No Elegant;
*/

class Solution {
public:
    string addBinary(string a, string b) {
        if(!a.size() || !b.size()) return a.empty()? b: a;
        string result;
        int c = 0;
        while(!a.empty() && !b.empty()) {
            int ar = int(a.back() - '0');
            int br = int(b.back() - '0');
            a.pop_back();
            b.pop_back();
            int n = ar^br^c;
            c = ((br|ar) & c) | (ar & br);
            result.insert(result.begin(), char(n + '0'));
        }
        while(!a.empty()) {
            int t = int(a.back() - '0');
            int n = t ^ c;
            a.pop_back();
            c = c & t;
            result.insert(result.begin(), char(n + '0'));
        }
        while(!b.empty()) {
            int t = int(b.back() - '0');
            int n = t ^ c;
            b.pop_back();
            c = c & t;
            result.insert(result.begin(), char(n + '0'));
        }
        if(c) result.insert(result.begin(), '1');
        return result;
    }
};
