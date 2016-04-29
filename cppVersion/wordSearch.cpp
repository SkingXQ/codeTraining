/*
https://leetcode.com/problems/word-search/
	I make a lot of problem
	1. First , I use back tracing but forget to mark the route is searching and forget to restore it .
	2. run time error sometime means I make a mistake in range for example x belong to (0, num.size())
		not (1, num.size()-1) and so on
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(!word.size()) return false;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(remindRoute(board, i, j, word, 0, 5)) return true;
                }
            }
        }
        return false;
    }
    
    bool remindRoute(vector<vector<char>>& board, int x, int y, string& word, int z, int direction) {
        if(word[z] != board[x][y]) return false;
        if(z == word.size()-1) return true; 
        char b = board[x][y];
        board[x][y] = '\0';
        bool result1 = false;
        bool result2 = false;
        bool result3 = false;
        bool result4 = false;
        if(x-1 >= 0  && direction != 2) {
            result1 = remindRoute(board, x-1,  y, word, z+1, 1);
            if(result1){
                board[x][y] = b;
                return true;
            }
        }
        if(x+1 < board.size()  && direction != 1) {
            result2 = remindRoute(board, x+1,  y, word, z+1, 2);
            if(result2) {
                board[x][y] =b;
                return true;
            }
        }
        if(y-1 >= 0 && direction != 4) {
            result3 = remindRoute(board, x,  y-1, word, z+1, 3);
            if(result3) {
                board[x][y] = b;
                return true;
            }
        }
        if(y+1 < board[0].size() && direction != 3) {
            result4 = remindRoute(board, x,  y+1, word, z+1, 4);
            if(result4) {
                board[x][y] = b;
                return true;
            }
        }
        board[x][y] = b;
        return false;
        
    }
};
