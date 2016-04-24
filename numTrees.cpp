/*Solution 1: Basicly iterately tracing
class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        int result = nums(1, n);
        cout<<result<<endl;
        return result;
    }
    int nums(int begin, int end){
        if(begin == end) return 1;
        int result = 0;
        for(int i = begin+1; i < end; i++){
            if(i == begin)
                result += nums(i+1, end);
            else if(i == end)
                result += nums(begin, i-1);
            else{
                result += nums(i+1, end)*nums(begin, i-1);
            }
        }
        return result;
    }
};*/
/* Solution 2: 
    Key Points: from 1 to 3 is equal to 3 to 5;
                means dp[i] is the num of i iterval (for example the tress is same when 1 to 3 or 3 to 5)
                be careful of the i initial value ,dp[0] and dp[1] is 1 and the rest is 0
                when i = 3, 1: left interval is 1, and right is 1;
                            2: left is zero and right is 2;
                            3: left is 2 and right is 0;
    */
class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1) return 1;
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= i; j++)
                dp[i] += dp[j] * dp[i-j-1]; 
        }
        return dp[n];
    }
};
