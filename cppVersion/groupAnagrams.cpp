/*
   link: https://leetcode.com/problems/anagrams/
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string, vector<string>> t;
        int position = 0;
        for(auto str : strs){
            string temp = str;
            sort(temp.begin(), temp.end());
            t[temp].push_back(strs[position++]);
        }
        for(auto tt : t){
            sort(tt.second.begin(), tt.second.end());
            result.push_back(tt.second);
        }
        return result;
    }
};
