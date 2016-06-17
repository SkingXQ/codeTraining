/*
    Link: https://leetcode.com/problems/rotate-image/
    Tips:  for example 1, 2, 3, 4
                       5, 6, 7, 8
                       9, 10,11,12
                       12,14,15,16
           one time rotate four number, It means you don't need to scan all number.
           as testing case, you scan 1, 2, 3, 6,
           the change rule as program write
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int ts = matrix.size() - 1;
        if(!ts) return;
        int begin = 0;
        int end = ts - 1;
        for(int j=0; j < ts/2 + (ts%2); j++) {
            for(int i=begin; i <= end; i++) {
                int t = matrix[j][i];
                matrix[j][i] = matrix[ts-i][j];
                matrix[ts-i][j] = matrix[ts-j][ts-i];
                matrix[ts-j][ts-i] = matrix[i][ts-j];
                matrix[i][ts-j] = t;
            }
            end--;
            begin++;
        }
        return;
    }
};
