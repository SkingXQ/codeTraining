/*
    Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    Tips: the difference of question i and question ii is that question i ask for the heighest trends of the array, however ii is 
          ask the continuous trends in the array
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        prices.insert(prices.begin(), INT_MAX);
        prices.push_back(INT_MIN);
        int maxCur = 0;
        int low = 0;
        int high = 0;
        bool buy = true;
        for(int i=1; i<prices.size()-1; i++) {
            if(buy) {
                if(prices[i] <= prices[i-1] && prices[i] < prices[i+1]) {
                    buy = false;
                    low = prices[i];
                }
            }else {
                if(prices[i] > prices[i-1] && prices[i]>=prices[i+1]){
                    buy = true;
                    high = prices[i];
                    res += high - low;
                }
            }
        }
        return res;
    }
};
