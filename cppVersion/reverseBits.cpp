/*
    Link: https://leetcode.com/problems/reverse-bits/
    Solution: http://bookshadow.com/weblog/2015/03/08/leetcode-reverse-bits/
    Tips: nothins special
*/
#include<iostream>
#include<bitset>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(!n) return n;
        for(int i=0; i<16; i++) {
            swapBits(n, i, 31-i);
            cout<<n<<endl;
        }
        return n;
    }
    void swapBits(uint32_t& n, int i, int j) {
       int a = (n >> i) & 1;
       int b = (n >> j) & 1;
       if((a ^ b) != 0) {
           n ^= ((1<<i) | (1<<j));
       }
    }
    
};

int main() {
    Solution t ;
    cout<<bitset<32>(t.reverseBits(3))<<endl;
}
