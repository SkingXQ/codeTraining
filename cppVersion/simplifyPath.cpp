/*
	link: https://leetcode.com/problems/simplify-path/
	I make a stupid mistake for taking .. 
*/
class Solution {
public:
    string simplifyPath(string path) {
         vector<string>  stackForPath;
         stackForPath.push_back("/");
         int j=0;
         if(path[path.size()-1] != '/')
            path.push_back('/');
         for(int i=1; i != path.size(); i++){
             if(path[i] == '/' ) {
                 if(path[i-1] == '/' ){
                     j = i;
                     continue;
                 }else{
                     if(path.substr(j+1, i-j-1) == ".."){
                         int t = 1;
                         while(t != 0) {
                             if(stackForPath.size() != 1){
                                 stackForPath.pop_back();
                                 stackForPath.pop_back();
                             }
                             t--;
                         }
                     }else if(path.substr(j+1, i-j-1) != "."){
                         stackForPath.push_back(path.substr(j+1, i-j-1));
                         stackForPath.push_back("/");
                     }
                    j = i;
                 }
             }
         }
         string result;
         if(stackForPath.size() == 1) result = "/";
         else{
             for(auto i=stackForPath.begin(); i != stackForPath.end()-1; i++)
                result += *i; 
         }
         return result;
    }
};
