/*
    link: https://leetcode.com/problems/longest-palindromic-substring/
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 1, max_start =  0;
        for(int i = 0; i < s.size();){
            if(s.size() - i < max_len/2) break;//try to test whether the rest enough for substring
            int k = i, j = i;
            while(k < s.size()-1 && s[k+1] == s[k]) k++;//in case of "xxxxasdattadsaxxxxxxxxx"
            i = k+1;
            while(k<s.size()-1 && j>0 && s[k+1] == s[j-1]){
                k++;
                j--;
            }
            if(max_len < (k-j+1)){
                max_len = k-j+1;
                max_start = j;
            }
        }
        return s.substr(max_start, max_len);
    }
};
