/*
    Link: https://leetcode.com/problems/water-and-jug-problem/
    Another solution: https://leetcode.com/discuss/110525/a-little-explanation-on-gcd-method
    Tips: About the greatest common divisor , I should remember it.
	  int gcd(int a, int b) {
	      return b == 0? a: gcd(b, a%b);
	  }
	  The explanation about why using gcd here is the same thoughts about it.
          the z must be the min * i + carry, the carry is the digit whose gcd is the same as x, y.
          it means anyone which z is smaller than x+y share the gcd with x ,y
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
