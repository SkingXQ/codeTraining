/*
    Link: https://leetcode.com/problems/minimum-height-trees/
    Discuss: http://www.cnblogs.com/grandyang/p/5000291.html
    Tips:
         My very begin thought to solve the problem is similar. I will cut off the leaves but I don't know where to stop
         It seems the result is no more than 2?
         BTW, I think the steps of discuss is beautiful!
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n == 1) return {0};
        vector<int> degree(n, 0);
        queue<int> q;
        vector<vector<int>> g(n, vector<int>());
        for(auto e : edges) {
            g[e.first].push_back(e.second);
            ++degree[e.first];
            g[e.second].push_back(e.first);
            ++degree[e.second];
        }
        
        for(int i=0; i<degree.size(); i++) {
            if(degree[i] == 1) {
                q.push(i);
                degree[i] = 0;
            }
        }
        
        while(n > 2) {//result no more than 2?  why?
            queue<int> t;
            while(!q.empty()) {
                int tmp = q.front();
                q.pop();
                --n;
                for(auto n : g[tmp]) {
                    --degree[n];
                    if(degree[n] == 1) t.push(n);
                }
            }
            q = t;
        }
        
        vector<int> result;
        while(!q.empty()) { //no member "begin" in queue(end too) so we have no method to use iterator here like(for (auto i : q))
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};
