# coding=utf-8
/*link:  https://leetcode.com/problems/burst-balloons/out<<"herdde"<<s<<"t"<<endl;
    define array,  index is the scale of nums, left to right ,
    scan the scale, divide two parts left to i , i to right and left * i * right(left <= i <= right)
    作为动态规划，我们可以这么说从最少的3个元素开始一组，然后到最长元素。
    之后对应思考，可以将一个区间分割为两个区间，不断的扫描，
    总有一次可以扫描到最优策略的切割路线，即不断的丢弃元素之后留下的最后三个元素
    这样子可以扫描出N个元素时候，各组的最优解。
    注意前面复制的写法，非常优秀。
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int num[nums.size()+2];
        int n = 1;
        for(auto x : nums) num[n++] = x;
        num[0] = num[n++] = 1;
        int dp[n][n] = {};
        for(int i = 2; i < n; i++){
            for(int left = 0; left + i < n; left++){
                int right = left + i;
                for(int di = left + 1; di < right; di++){
                    dp[left][right] = max(dp[left][right], \
                                          dp[left][di] + dp[di][right] + num[left] * num[right] * num[di]);
                }
            }
        }
        cout<<dp[0][n-1]<<endl;
        return dp[0][n-1];
    }
};
