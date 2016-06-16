/*
    Link: https://leetcode.com/problems/gas-station/
    Tips: if sum(gas-  cost)<0 ,return fail
          else find the break point where sum of right part number is maxium so that [sum(right) , left part] is non break list;
               if sum(left) continue growing with going through the vector(gas - cost), It means every point of the right part is 
               works accoding the condition.
               
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() == 0) return -1;
        long long int sumLeft = 0;
        for(auto i=gas.begin(), j=cost.begin(); i != gas.end(); i++, j++) {
            *i = *i - *j;
            sumLeft += *i;
        }
        if(sumLeft < 0) return -1;
        int result = gas.size() - 1;
        long long int sumRight = 0;
        int breakPoint = -1;
        long long int max = 0;
        for(; result >= 0; result--) {
            if(sumRight+gas[result] >= max) {
                breakPoint = result;
                max = sumRight+gas[result];
            }
            sumRight += gas[result];
        }
        return breakPoint;
    }
};
