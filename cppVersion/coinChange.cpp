/* Link: https://leetcode.com/problems/coin-change/
 * Solution: http://www.cnblogs.com/grandyang/p/5138186.html
 *           http://www.xuebuyuan.com/2119255.html
 *           http://blog.csdn.net/ditian1027/article/details/24310641
 * Tips: direction and initial
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1, amount+1);
        ans[0] = 0;
        int s = coins.size();
        for(int i=1; i<amount+1; i++) {
            for(int j=0; j<s; j++) {
                if(i-coins[j] >= 0) ans[i] = min(ans[i], ans[i-coins[j]]+1);
            }
        }
        return ans[amount]==amount+1? -1: ans[amount];
    }
};

int main() {
    vector<int>  a = {3,5};
    Solution t;
    cout<<t.coinChange(a, 7)<<endl;;
}
