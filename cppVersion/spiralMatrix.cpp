/*
    link : https://leetcode.com/problems/spiral-matrix/
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0) return result;
        if(matrix.size()==1){
            result.insert(result.begin(), matrix[0].begin(), matrix[0].end());
            return result;
        }
        if(matrix[0].size() == 0) return result;
        result.insert(result.begin(), matrix[0].begin(), matrix[0].end());
        matrix.erase(matrix.begin());
        for(auto i=matrix.begin(); i != (matrix.end()-1); i++) {
            result.push_back(i->back());
            i->pop_back();
        }
        result.insert(result.end(), matrix.back().rbegin(), matrix.back().rend());
        matrix.erase(matrix.end()-1);
        if(matrix[0].size() == 0) return result;
        for(auto i=matrix.rbegin(); i != (matrix.rend()); i++) {
            result.push_back(i->front());
            i->erase(i->begin());
        }
        vector<int>  tmp = spiralOrder(matrix);
        result.insert(result.end(), tmp.begin(), tmp.end());
        return result;
    }
};
