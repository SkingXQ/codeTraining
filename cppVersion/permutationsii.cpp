/*
link : https://leetcode.com/problems/permutations-ii/
*/

class Solution {
    /*
    Backtracking, using map instead of vector.
    Depth first searching, DFS. searching the tree,
    once the node indicate the nums used, remove from database, 
    when backtracking, put back the data to database till iterate to original situation. 
    
    Testing the result with & or without &,
          if we want changingt the origin data ,use &
        for(auto &i : mapNums){
            i.second = 0;
            cout<<mapNums[i.first]<<endl;
        }
    */
/* segment fault
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int>  mapNums;
        int size  = nums.size();
        for(auto i = nums.begin(); i != nums.end(); i++ ){
            mapNums[*i] += 1;
        }
        vector<vector<int>> result;
        for(int i =0; i<size;i++){
            nums.pop_back();
        }
        backtracking(mapNums, result, nums);
        return result;
    }
    void backtracking(map<int, int>& mapNums, vector<vector<int>>& result, vector<int>& t){
        if(mapNums.size() == 0){
            result.push_back(t);
            return;
        }
        for(auto i : mapNums){
            t.push_back(i.first);
            mapNums[i.first] -= 1;
            if(mapNums[i.first] == 0){
                mapNums.erase(i.first);
            }
            backtracking(mapNums, result, t);
            if(mapNums.find(i.first) == mapNums.end())
                mapNums[i.first] = 1;
            else
                mapNums[i.first] += 1;
            t.pop_back();
        }
        
    }*/
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};
