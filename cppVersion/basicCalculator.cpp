/*
    link: https://leetcode.com/problems/basic-calculator/
*/
class Solution {
    /*匈牙利算式， 数据结构中介绍栈的部分有说明。
    vector的pop_back,不是真的删除，而是改变下size的大小跟边界*/
public:
    int calculate(string s) {
        if(s == "") return 0;
        vector<int> numRow;
        vector<char> symbol;
        int count = 0;
        bool flag = true;
        for(auto c : s){
            if(c >= '0' && c <= '9'){
                count = int(c-'0') + count * 10;
                if(flag) flag = false;
            }else if(c == '+' || c == '-'){
                if(!flag){
                    numRow.push_back(count);
                    flag = true;
                    count = 0;
                }
                if( symbol.size() != 0){
                    if(symbol.back() == '-'){
                        minus(numRow);
                        symbol.pop_back();
                    }else if(symbol.back() == '+'){
                        plus(numRow);
                        symbol.pop_back();
                    }
                }
                symbol.push_back(c);
            }else if(c == '('){
                symbol.push_back(c);
            }else if(c == ')'){
                if(!flag){
                    numRow.push_back(count);
                    flag = true;
                    count = 0;
                }
                if(symbol.back() == '-'){
                    minus(numRow);
                    symbol.pop_back();
                }else if(symbol.back() == '+'){
                    plus(numRow);
                    symbol.pop_back();
                }
                symbol.pop_back();
            }
        }
        if(!flag) numRow.push_back(count);
        if(symbol.size() == 0) return numRow.back();/*
        for(auto i = symbol.rbegin(); i != symbol.rend();i++){
            if(*i == '-') minus(numRow);
            else plus(numRow);
        }*/
        else{
            cout<<"out"<<endl;
            if(symbol.back() == '+') plus(numRow);
            else minus(numRow);
        }
        return numRow.back();
    }
    
    void plus(vector<int>& numRow){
        int i = numRow[numRow.size()-2] + numRow[numRow.size()-1];
        numRow.pop_back();
        numRow.pop_back();
        numRow.push_back(i);
    }
    
    void minus(vector<int>& numRow){
        int i = numRow[numRow.size()-2] - numRow[numRow.size()-1];
        numRow.pop_back();
        numRow.pop_back();
        numRow.push_back(i);
    }
};
