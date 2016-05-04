/*
    link: https://leetcode.com/problems/decode-ways/
*/

/*
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int a = 1, b= 0, cur = 0;
        int i = s.size();
        while(i--){
            if(s[i] == '0') cur = 0;
            else if(stoi(s.substr(i,2))<=26) cur = a+b;
            else cur = a;
            b = a;
            a = cur;
        }
        return cur;
    }
};
reverse is better
please think more rigorously
*/

class Solution {
public:
    int numDecodings(string s) {
        int cur = 1;
        int sig = 1;
        int temp = 1;
        if(s == "" || s.substr(0,1) == "0" ) return 0;
        if(s.substr(s.size()-1, 1) == "0" && stoi(s.substr(s.size()-2,1)) >2){
            return 0;}
        for(int index = 1; index < s.size(); index++){
            if(stoi(s.substr(index-1, 2))<=26 && stoi(s.substr(index-1, 2)) >10 \
                    && stoi(s.substr(index-1, 2)) <30 && (stoi(s.substr(index, 2))%10)\
                    && (stoi(s.substr(index-1, 2))%10)){
                temp = cur;
                cur = cur+sig;
                sig = temp;
                cout<<"shit"<<index<<endl;
            }else if(s.substr(index, 1) != "0"){
                cur = cur;
                sig = cur;
                cout<<"fuc"<<index<<endl;
            }else if(s.substr(index-1, 2) == "00"){
                cur = 0;
                break;
            }else if(stoi(s.substr(index-1, 2))>20 && stoi(s.substr(index, 2)) <10){
                cur = 0;
                break;}
        }
        return cur;
    }
};
