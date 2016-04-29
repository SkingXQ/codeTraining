/*
    link:   https://leetcode.com/problems/triangle/
    Solution:  https://leetcode.com/discuss/5337/dp-solution-for-triangle
    method:
	from second bottom layer, We could know:
	1. the size of layer is equal to layer
	2. in the end , second bottom layer will chose the layer number way to continue
	So each loop, reduce the routing utill 1;
                      2
                    3   4
                  6   5    7
                9   5   13   1
        first step , extral memory store 9, 5, 13, 1
        first loop, 6,5,7 will chose the short way , and record result to 11, 10 , 8, 1;
	and so on 
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> route = triangle.back();
        for(int layer = n-2; layer >= 0; layer--){
            for(int i=0; i <= layer; i++) {
                route[i] = min(route[i], route[i+1]) + triangle[layer][i];
            }
        }
        return route[0];
    }
};
