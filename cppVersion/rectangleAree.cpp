/*
link https://leetcode.com/problems/rectangle-area/
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaOne = (C-A) * (D-B);
        int areaTwo = (G-E) * (H-F);
        int width = overlapping(pair<int, int>(E, G), pair<int, int>(A, C));
        int highth = overlapping(pair<int, int>(B, D), pair<int, int>(F, H));
        return areaOne + areaTwo - width * highth;
        }
    
    int overlapping(pair<int, int>line1, pair<int, int>line2){
        if(line1.first < line2.first){
            swap(line1, line2);
        }
        if(line1.first > line2.second){
            return 0;
        }
        int end = min(line1.second, line2.second);
        return end - line1.first;
    }
};
