/*
    link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
class Solution {
public:
    /*  Scan the string and remember the existing characters
    using the vector to store the char position,
    compare the pre length with distance between same chars to determine the longest length.
    mark the the position behind the repeating characters.
    在重复字母出现时候，前方有一最长无重复字母子串，那么记录目前最长子串，可能在第一次出现之前，
    或者在两个之间，记录，之后丢弃第一个自字符串之前数据，重新扫描
    
    I think too much situations and pleas remember tweo standards:
    1 useing the ASCII value to mark the array
    2 from head to rear, step by step will filt a lot complex situations
    需要注意的是，从头扫描到尾部，这种行为有时候可以认为是 一种动态规划的步骤，也就是说，前面有一暂时优解，并继续加入字符，
    需要注意的是，丢弃第一次出现字母前面字符串的理由，我们可以认为前面的字母对后面已经没有影响了。
    */
    int lengthOfLongestSubstring(string s) {
        int startPosition = 0;
        int longest = 0;
        vector<int> charStock(256, -1);
        for(int i = 0; i < s.size(); i++){
            startPosition = max(charStock[s[i]]+1, startPosition);
            charStock[s[i]] = i;
            longest = max(longest, i-startPosition+1);
        }
        return longest;
    }
};
