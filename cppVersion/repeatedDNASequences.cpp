/*
    Link: https://leetcode.com/problems/repeated-dna-sequences/
    Discuss: https://leetcode.com/discuss/79094/easy-understand-and-straightforward-java-solution
    Tips: great solution. Used the hash to check the duplicated
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10) return {};
        //vector<string> res;
        unordered_set<string> t;
        unordered_set<string> t1;
        cout<<"he"<<endl;
        for(int i=0; i< s.size()-9; i++) {
            if(t.find(s.substr(i, 10)) == t.end()) {
                t.insert(s.substr(i, 10));
            } else {
                t1.insert(s.substr(i, 10));
            }
        }
        vector<string> res(t1.begin(), t1.end());
        return res;
    }
};
/*class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10) return {};
        //vector<string> res;
        unordered_set<string> t;
        for(int i=0; i< s.size()-10; i++) {
            if(t.find(s.substr(i, 10)) == t.end()) {
                if(findSecond(s.substr(i+1), s.substr(i, 10))) {
                    t.insert(s.substr(i, 10));
                }
            }
        }
        vector<string> res(t.begin(), t.end());
        return res;
    }
    
    bool findSecond(string s, string pattern) {
        for(int i=0; i<s.size()-9; i++) {
            if(s.substr(i, 10) == pattern)
                return true;
        }
        return false;
    }
};*/
