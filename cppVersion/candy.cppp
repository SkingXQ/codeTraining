/*
    Link: https://leetcode.com/problems/candy/
    Discuss: https://leetcode.com/discuss/92299/simple-c-dp-solution-36ms-beats-88%25-submissions
    Tips:In the very beginning , I try to solve it by going through the array, and increase the score or decrease the score
         according to the trend of the ratings. But I found I need to ajust the score several times with the time complexity O(N2);
         The discussion remind me of that we just need to ajust the score according the increase.
         Go through the array from head to rear and reverse it again.
         By the way . the question describe that "Children with a higher rating get more candies than their neighbors."
         It means the same ratings is neighbors but one will be lower than another. :)
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0;
        vector<int> score(ratings.size(), 1);
        for(int i=1; i<ratings.size(); i++) {
            if(ratings[i] > ratings[i-1])
                score[i] = score[i-1] +1;
            //if(ratings[i] == ratings[i-1]) 
             //   score[i] = score[i-1];
        }
        for(int i=ratings.size()-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]  && score[i] <= score[i+1]+1)
                score[i] = score[i+1] +1;
           // if(ratings[i] == ratings[i-1] && score[i] <= score[i+1]) 
            //    score[i] = score[i+1];
        }
        for(auto i: score)
            res += i;
        
        return res;
    }
};
