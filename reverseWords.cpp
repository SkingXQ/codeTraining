/*  https://leetcode.com/problems/interleaving-string/
	becare for the situation:
	1. ""
	2. "   "
	3."sking is     blue"
        4."sking is blue  "or "   sking is blue"

        initial the class with no parameters, use:\
	Solution a; not Solution a();
*/
#include<string>
#include<iostream> 
using namespace std;

class Solution {
public:
    Solution() = default;
    Solution(int t);
    void reverseWords(string &s) {
        if(s.length() == 0) return;
        int begin=0;
        while(*(s.end()-1) == ' '){
            s.erase(s.length()-1, 1); 
        }   
        for(int i=0; i < s.length();){
            if(s[i] == ' '){
                if(begin == i){ 
                    s.erase(begin, 1); 
                }else{
                    rever(s, begin, i-1);
                    i++;
                    begin = i;
                }   
            }else{
                 i++;
            }   
        }   
        rever(s, begin, s.length()-1);
        rever(s, 0, s.length()-1);
    }   
  
    void rever(string &s, int begin, int end){
        while(begin < end){
            swap(s[begin++], s[end--]);
        }   
     }   
  };  
  
Solution::Solution(int t){
	cout<<t<<endl;
}

int main(){
      Solution a(1);
      string t = "sking is     blue ";
      a.reverseWords(t);
      cout<<t<<endl;
      return 0;
}
