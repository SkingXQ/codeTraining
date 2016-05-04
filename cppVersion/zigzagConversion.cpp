/*
    link: https://leetcode.com/problems/zigzag-conversion/
*/
class Solution {
public:
    string convert(string s, int numRows) {
		int size = s.length();
		if(size<2 || numRows < 2) return s;
		string res;
		int step = 2 * numRows - 2;
		for (int i = 0; i<numRows; i++){
			bool turn = true;
			for (int j = i; j<size;){
				if (i != 0 && i != (numRows - 1)){
					if (turn){
						step = 2 * numRows - 2 - 2 * i;
					}
					else{
						step = 2*i;
					}
					res += s[j];
					j += step;
					turn = !turn;
				}
				else{
					step = 2 * numRows - 2;
					res += s[j];
					j += step;
				}
			}
		}
		return res;
	};
};
