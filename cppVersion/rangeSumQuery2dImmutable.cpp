/*
    link: https://leetcode.com/problems/range-sum-query-2d-immutable/
    Reference: https://leetcode.com/discuss/104719/short-and-efficient-solution-time-space-with-precomputation
    Tips:
        Actually I think it out with the help of link's title. It remind me of that for save time I have to restore some data in initial step,
        Finally I figure it out.
       restoreMatrix restores the sum of 2d retangle for matrix[0][0] to matrix[i][j]
*/
#include<iostream>
#include<vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> restoreMatrix;
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0) return;
        vector<int> firstLine = {matrix[0][0]};
        for(auto k=matrix[0].begin()+1; k != matrix[0].end(); k++)
            firstLine.push_back(firstLine.back() + *k);
        restoreMatrix.push_back(firstLine);
        for(int i=1; i != matrix.size(); i++)
        {
            vector<int> tmp = {restoreMatrix.back()[0] + matrix[i][0]};
            for(int j=1; j != matrix[i].size(); j++)
            {
                tmp.push_back(matrix[i][j] + tmp[j-1] + restoreMatrix[i-1][j] - restoreMatrix[i-1][j-1]);
            }
            restoreMatrix.push_back(tmp);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0)
            return restoreMatrix[row2][col2];
        else if(row1 == 0 && col1 != 0)
            return restoreMatrix[row2][col2] - restoreMatrix[row2][col1-1];
        else if(row1 != 0 && col1 == 0)
            return restoreMatrix[row2][col2] - restoreMatrix[row1-1][col2];
        else
            return restoreMatrix[row2][col2] - restoreMatrix[row1-1][col2] - restoreMatrix[row2][col1-1] + restoreMatrix[row1-1][col1-1];

    }
};


int main() {
    vector<vector<int>> m = {
      {3, 0, 1, 4, 2},
      {5, 6, 3, 2, 1},
      {1, 2, 0, 1, 5},
      {4, 1, 0, 1, 7},
      {1, 0, 3, 0, 5}
    };
    NumMatrix a(m);
    cout<<a.restoreMatrix.size()<< " "<< a.restoreMatrix[0].size()<<endl;
    for(auto i=a.restoreMatrix.begin(); i != a.restoreMatrix.end(); i++)
    {
        for(auto j = (*i).begin(); j != (*i).end(); j++)
        {
            cout<<*j<<"  ";
        }
        cout<<endl;
    }
    cout<<a.sumRegion(0, 0, 2, 2)<<endl;
    cout<<a.sumRegion(0, 1, 2, 2)<<endl;
    cout<<a.sumRegion(1, 0, 2, 2)<<endl;
}

