/*
    Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    Discuss: https://leetcode.com/discuss/48378/kadanes-algorithm-since-mentioned-about-interviewer-twists
    Tips: the calculation of difference between the current number and previous one will indicate the trending of current array.
          For example "1,5, 15, 1", the acccumulation will be 4,14,0, it means the trend touch down.
           "2, 13, 15, 1" , the accumulation  will be 11, 13, -1, it means the lowest number will change.
          the maxSoFar will store the maximum difference so far.
          The algorithm just used for the situation that we need to get the upstream trend not downstream.
          Although the algorithm is more beautiful. But My thoughts is right, try to get the lowest number so far.
          keep the biggest differece(up stream) so far. and keep going on.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxSoFar = 0;
        int maxCur = 0;
        for(int i=1; i<prices.size(); i++) {
            maxCur = max(0, (maxCur += (prices[i] - prices[i-1])));
            maxSoFar = max(maxCur, maxSoFar);
        }
        return maxSoFar;
    }
};
