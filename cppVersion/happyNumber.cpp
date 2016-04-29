/*
   link: https://leetcode.com/problems/happy-number/
*/

class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0) return false;
        vector<int> tempOut;
        bool result = false;
        while(!result){
            int count = 0;
            while(n){
                count += (n%10) * (n%10);
                n /= 10;
            }
            vector<int>::iterator search = tempOut.begin();
            for(; search != tempOut.end(); ++search){
                if(*search == count) break;
            }
            
            if(count == 1){
                result = true;
                break;
            }else if(search != tempOut.end()){
                break;
            }else{
                tempOut.push_back(count);
                n = count;
            }
            cout<<count<<endl;
        }
        return result;
    }
};

/*bool isHappy(int n) {
    while(n>6){
        int next = 0;
        while(n){next+=(n%10)*(n%10); n/=10;}
        n = next;
    }
    return n==1;
}*/
