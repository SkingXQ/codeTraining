/*
	becare for the situation:
	1. ""
	2. "   "
	3."sking is     blue"
        4."sking is blue  "or "   sking is blue"
*/
#include<string>
#include<iostream> 
using namespace std;

class Solution {
public:
    Solution() = default;
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
        cout<<"here"<<s<<"t"<<endl;
    }   
  
    void rever(string &s, int begin, int end){
        while(begin < end){
            swap(s[begin++], s[end--]);
        }   
     }   
  };  
  
  int main(){
      Solution a;
      string t = "sking is     blue ";
      a.reverseWords(t);
      return 0;
}
