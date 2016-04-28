# coding=utf8
/*https://leetcode.com/problems/edit-distance/
    动态规划， dp[k][j]意味着s1的到K位置的子序列与s2到k子序列最少的修改数量
    关键点是d[k][j]递归
    dp构架时候加入一行一列，意味着当一个字符串为零时候最少修改数量
    此外，dp递归过程中，其实是一下几种情况
    ***     ***         ***        ***  以及  {**}  *
     ***      ***      ***       ***          {**}  *
     情况很好的是，2,4，情况已然被1,2所递归，所以，可以比对，1，2,5的情况如何
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word2 == "") return word1.size();
        int wordOneSize = word1.size();
        int wordTwoSize = word2.size();
        int dp[wordOneSize+1][wordTwoSize+1] = {};
        for(int i=0; i < wordTwoSize+1;i++) dp[0][i] = i;
        for(int i=1; i < wordOneSize+1;i++) dp[i][0] = i;
        for(int k=1; k < wordOneSize+1; k++){
            for(int j=1; j < wordTwoSize+1; j++){
                if(word1[k-1] == word2[j-1]){
                    dp[k][j] = min(dp[k-1][j-1], min(dp[k][j-1], dp[k-1][j]) + 1) ;
                }else{
                    dp[k][j] = min(dp[k-1][j-1], min(dp[k][j-1], dp[k-1][j])) + 1; 
                }
            }
                /*if(word1[k-1] == word2[j-1]){
                    dp[k][j] = dp[k-1][j-1];
                    for(int t = k-1; t > 0; t--){
                        dp[k][j] = min(dp[k][j], dp[t][j] + k - t);
                    }
                    for(int t = j-1; t > 0; t--){
                        dp[k][j] = min(dp[k][j], dp[k][t] + j - t);
                    }
                }else{
                    dp[k][j] = dp[k-1][j-1]+1;
                    for(int t = k-1; t > 0; t--){
                        dp[k][j] = min(dp[k][j], dp[t][j] + k - t);
                    }
                    for(int t = j-1; t > 0; t--){
                        dp[k][j] = min(dp[k][j], dp[k][t] + j - t);
                    }
                }*/
        }
        return dp[word1.size()][word2.size()];
    }
};
