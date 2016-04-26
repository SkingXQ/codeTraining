/*
    DFS Solution
    1 find the begin point 
    2 DFS search the end;
    3 mark the searched point 
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int column = grid[0].size();
        int count = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }
    
    void DFS(vector<vector<char>>& grid, int row, int column){
        if(row >= 0 && row < grid.size() && column >= 0 && column < grid[0].size() && grid[row][column] == '1'){
            grid[row][column] = '2';
            DFS(grid, row+1, column);
            DFS(grid, row-1, column);
            DFS(grid, row, column+1);
            DFS(grid, row, column-1);
        }
    }
};

/* Union Find：(the group is UFset)
    1 find land;
    2 do union
    3 when do union ,find the group number match them， if not in the same gropu
    return true
    Key Point:
    1 turn the 2d into a 1d array
    2 the group is a tree having two children, linked togather.find root and linked togather
    For example :
         1 1 1
         0 1 0
    the group = 1,2, 4, 0, 4, 0 
    For example :
         1 1 1
         1 1 0
    the group = 3, 2, 4, 3, 4, 0   
    it turns to heap
       4 
     2   3
  1     0   
*/
/*class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0 || column == 0) {
            return 0;
        }
        int column = grid[0].size();
        vector<int> group(row*column, 0);
        int count = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    group[idx(i, j, column)] = idx(i, j, column);
                    if(i > 0 && grid[i-1][j] == '1') { //&& Union(idx(i, j, column), idx(i-1, j, column), group))
                        Union(idx(i, j, column), idx(i-1, j, column), group);
                        count--;
                    }
                    if(i > 0 && grid[i][j-1] == '1') {// && Union(idx(i, j, column), idx(i, j-1, column), group))
                        Union(idx(i, j, column), idx(i, j-1, column), group);
                        count--;
                    }
                }
            }
        }
        return count;
    }
    
    bool Union(int x, int y, vector<int>& group) {
        int rootx = find(x, group);
        int rooty = find(y, group);
        //if(rooty == rootx) return false;
        group[rooty] = rootx;
        return true;
    }
    int find(int target, vector<int>& group) {
        return group[target]  == target? target : find(group[target], group);
    }
    int idx(int row, int column, int sizePer) {
        return row*sizePer + column;
    }
};*/
