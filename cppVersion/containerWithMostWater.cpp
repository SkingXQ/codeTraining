/*
    Link : https://leetcode.com/problems/container-with-most-water/
    Discuss: https://leetcode.com/discuss/11482/yet-another-way-to-see-what-happens-in-the-o-n-algorithm
    Tips: I make a mistake.  The contianner is depend on the shorted line. We can use two pointers to mark the lines' positions.
          And move the shorter one till go through the lines.
*/

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int maxArea = 0;
            int i = 0, j = height.size() - 1;
            while(i < j)
            {
                maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
                if(height[i] < height[j])
                    i++;
                else
                    j--;
            }
        return maxArea;
    }	
};
