/*
    Link: https://leetcode.com/problems/maximum-product-of-word-lengths/
    Solution: https://discuss.leetcode.com/topic/31766/bit-shorter-c/2
    Tips: Turn the string into int :
          for(auto w : word) 
                m |= 1<<(w-'a');
          that's amazing.
          mask[m] = max(mask[m], (int)word.size()); // in this case : "aa" and "aaaaaa"
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mask;
        int ret = 0;
        for(auto word : words) {
            int m = 0;
            for(auto w : word) 
                m |= 1<<(w-'a');
            mask[m] = max(mask[m], (int)word.size());
            for(auto ma : mask) {
                if(ma.first != m && !(ma.first & m))
                    ret = max(ret, ((int)word.size()) * ma.second);
            }
        }
        return ret;
    }
};
