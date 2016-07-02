/*
    Link: https://leetcode.com/problems/water-and-jug-problem/
    Another solution: https://leetcode.com/discuss/110235/c-solution-using-euclidean-algorithm
*/

#include<iostream>
#include<unordered_set>
using namespace std;


class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x==0 && y==0 && z!=0) return false;
        if(((x==0) || (y==0))) {
            if(x ==z || y ==z ) return true;
            else return false;
        }
        if(z == 0) return true;
        if(x+y < z) return false;
        if(x == z || y == z || x+y == z) return true;
        int ma = max(x, y); 
        int mi = min(x, y); 
        int mib = mi; 
        int i = 1;
        int carry = 0;
        while(mi != ma) {
            mi = mib * i + carry;
            if(mi < ma) {
                if(mi == z || mi+mib == z) return true;
                i++;
            }else if(mi > ma){
                if(mi-ma ==z || mi-ma+mib == z) return true;
                carry = mi-ma;
                mi = mib;
                i = 0;
            }   
        }   
        return false;
    }   
};
int main() {

    Solution a;
    a.canMeasureWater(3,5,4);
    return 0;
}
