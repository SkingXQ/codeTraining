/*
    link: https://leetcode.com/problems/permutations/
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        //if(nums.size() == 0) return result.push_back(vector<int> t);
        vector<int> temp;
        backtracking(nums, result, temp);
        return result;
    }
    void backtracking(vector<int>& inputArray, vector<vector<int>>& result, vector<int> &temp){
        if(inputArray.size() == 0){
            result.push_back(temp);
            return;
        }
        for(int i=0; i < inputArray.size(); i++){
            temp.push_back(inputArray[i]);
            inputArray.erase(inputArray.begin()+i);
            backtracking(inputArray, result, temp);
            inputArray.insert(inputArray.begin()+i, temp.back());
            temp.pop_back();
        }
    }
};
