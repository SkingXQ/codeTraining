/* https://leetcode.com/problems/largest-number/
   https://leetcode.com/discuss/21683/a-simple-c-solution
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>  tmp;
        for(auto i : nums)
            tmp.push_back(to_string(i));
        sort(tmp.begin(), tmp.end(), [](string& s1, string& s2){return s1+s2 > s2+s1;});
        string result;
        for(auto s : tmp)
            result += s;
        cout<<result<<endl;
        if(result[0] == '0')
            result = "0";
        return  result;
    }
};
