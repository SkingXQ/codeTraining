/*
    Link: https://leetcode.com/problems/dungeon-game/
    Solution: http://blog.csdn.net/ljiabin/article/details/42616291
    Tip: Dynamic Programming keys:
             1. dynamic function: not just for top left to bottom right, reversing is all right
                the number won't accumulate from end to begin;
             2. initial position: 1) add another begin postiom ; 2) initial alone
*/
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<limits>
using namespace std;

class Solution {  
public: 
    int calculateMinimumHP(vector<vector<int>>& dungeon) {  
            int m = dungeon.size();  
            int n = dungeon[0].size();  
              
            int ans[m][n];
              
            //初始化最后一行和最后一列  
            ans[m - 1][n - 1] = dungeon[m - 1][n - 1] > 0 ? 0 : -dungeon[m - 1][n - 1];  
            for (int i = m - 2; i >= 0; i--) {  
                ans[i][n - 1] = dungeon[i][n - 1] >= ans[i + 1][n - 1] ? 0 : ans[i + 1][n - 1] - dungeon[i][n - 1];  
            }  
            for (int j = n - 2; j >= 0; j--) {  
                ans[m - 1][j] = dungeon[m - 1][j] >= ans[m - 1][j + 1] ? 0 : ans[m - 1][j + 1] - dungeon[m - 1][j];  
            }  
              
            //从右下角往左上角遍历  
            for (int i = m - 2; i >= 0; i--) {  
                for (int j = n - 2; j >= 0; j--) {  
                    int down = dungeon[i][j] >= ans[i + 1][j] ? 0 : ans[i + 1][j] - dungeon[i][j];  
                    int right = dungeon[i][j] >= ans[i][j + 1] ? 0 : ans[i][j + 1] - dungeon[i][j];  
                    ans[i][j] = min(down, right);  
                }  
            }  
              
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++) cout<<ans[i][j]<<" ";
                cout<<endl;
            }
            //要保证勇士活着，至少需要1魔力  
            return ans[0][0] + 1;  
        }  
};  
/*class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int column = dungeon.size();
        int row = dungeon[0].size();
        vector<int> tp(row+1, -10000);
        tp[1] = 0;
        vector<vector<int> > path(column+1, tp);
        dungeon.insert(dungeon.begin(), vector<int>(row, -10000));
        for(int i=0; i<dungeon.size(); i++)
            dungeon[i].insert(dungeon[i].begin(), -10000);
        dungeon[1][0] = 0;
        dungeon[0][1] = 0;
        for(int i=1; i<column+1; i++) {
            for(int j=1; j<row+1;j++) {
                int t1 = max((1-(dungeon[i][j]+dungeon[i-1][j])), path[i-1][j]);
                int t2 = max(1-(dungeon[i][j]+dungeon[i][j-1]), path[i][j-1]);
                if(t1 >= t2) {
                    dungeon[i][j] += dungeon[i][j-1];
                    path[i][j] = t2;
                }else {
                    dungeon[i][j] += dungeon[i-1][j];
                    path[i][j] = t1;
                }
            }
        }
        for(int i=0; i<column+1; i++) {
            for(int j=0; j<row+1;j++)
                cout<<path[i][j]<<" ";
            cout<<endl;
        }
        return 1;
    }
};
*/
int main() {
    vector<vector<int>> dungeon = {{1,-3,3},{0,-2,0},{-3,-3,-3}};// = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    Solution t;
    t.calculateMinimumHP(dungeon);
    return 0;
}
