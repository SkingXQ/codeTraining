/*
    link: https://leetcode.com/problems/reverse-words-in-a-string/
*/
class Solution {
public:
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
