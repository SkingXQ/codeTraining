/*
    Link:https://leetcode.com/problems/minimum-path-sum/
    Discuss : https://leetcode.com/problems/minimum-path-sum/
    Tips: method 1 is my thoughts and too many redundant path
          method 2 is from the discuss. It optimizes the path.
          For example, 7, 8, 9
                       4, 5, 6
                       1, 2, 3
          when reaching 5, it has two ways. 7->8->5 and 7->4->5
          So we chose 7->8->5 with the method of discuss.
          Yes , it's dynamic programming.
*/


/*class Solution {
private:
    int first = -1;
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(!grid.size() || !grid[0].size()) return 0;
        minPathSum(grid, 0, 0, 0);
        return first;
    }

    void minPathSum(vector<vector<int>>& grid, int startX, int startY, int pathSum) {
        if(startX == grid.size()-1 && startY == grid[0].size()-1) {
            first = first>pathSum+grid[grid.size()-1][grid[0].size()-1]? first: pathSum+grid[grid.size()-1][grid[0].size()-1];
            return;
        }
        
        if(startY == grid[0].size()-1){
            pathSum += grid[startX][startY];
            minPathSum(grid, startX+1, startY, pathSum);
            return;
        }
        
        if(startX == grid.size()-1) {
            pathSum += grid[startX][startY];
            minPathSum(grid, startX, startY+1, pathSum);
            return;
        }
        
        doubleDirect(grid, startX, startY, pathSum);
    }
    
    void doubleDirect(vector<vector<int>>& grid, int startX, int startY, int pathSum) {
            pathSum += grid[startX][startY];
            minPathSum(grid, startX, startY+1, pathSum);
            minPathSum(grid, startX+1, startY, pathSum);
            return;
    }
};*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int xsize = grid.size();
        if(xsize == 0){
            return 0;
        }
        int ysize = grid[0].size();
        vector<int> d(ysize + 1, 0);
        for(int i = 1; i <= ysize; ++i){
            d[i] = d[i - 1] + grid[0][i - 1];
        }
        d[0] = grid[0][0];
        for(int i = 2; i <= xsize; ++i){
            d[0] += grid[i - 1][0];
            for(int j = 1; j <= ysize; ++j){
                d[j] = min(d[j], d[j - 1]) + grid[i - 1][j - 1];
            }
        }
        return d[ysize];
    }
    
};
