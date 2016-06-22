/*
    Link:https://leetcode.com/problems/search-a-2d-matrix/
    Tips: binarySearch
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size() || !matrix[0].size()) return false;
        for(auto i=matrix.begin(); i!=matrix.end(); i++) {
            if(i == matrix.end()-1) return divideSearch(*i, 0, i->size()-1, target);
            if(target>=(*i)[0] && target<(*(i+1))[0])
                return divideSearch(*i, 0, i->size()-1, target);
        }    
        return false;
    }   

    bool divideSearch(vector<int>& array, int begin, int end, int target) {
        if(end == begin) return array[end] == target;
        if(end > begin) {
            if(array[begin+(end-begin)/2] >= target) 
                return divideSearch(array, begin, begin+(end-begin)/2, target);
            else if(array[begin+(end-begin)/2] < target) 
                return divideSearch(array, begin+1+(end-begin)/2, end, target);
        }   
        return false;
    }   
};

int main() {
    vector<vector<int>> a = {
                             {1},
                             {10},
                             {23}
                            };
    Solution t ;
    cout<<(t.searchMatrix(a, 7))<<endl;
    return 0;
}
