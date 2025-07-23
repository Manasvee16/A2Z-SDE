//The effort of a path is the maximum height difference you encounter on that path. The goal is to find a path where this maximum height difference is as small as possible.
class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> paths; //o explore cells with the least effort first.
        vector<vector<int>> visited(n, vector<int>(m, 1e9));
        paths.push({0, {0, 0}}); //{effort, {x, y}}
        visited[0][0] = 0; //visited[i][j] stores the minimum effort needed to reach cell (i,j)
        while (!paths.empty()) {
            int min_effort = paths.top().first; //max absolute difference of heights encountered so far in the path to (x, y)
            int x = paths.top().second.first;
            int y = paths.top().second.second;
            paths.pop();
            if (x == n - 1 && y == m - 1)
                return min_effort;
            for (int i = 0; i < 4; i++) {
                int newi = x + dx[i];
                int newj = y + dy[i];
                if (newi >= 0 && newj >= 0 && newi < n && newj < m) {
                        int new_min_effort = max(min_effort, abs(heights[newi][newj] - heights[x][y])); //effort to go from (x,y) to (newi,newj). Your new path’s effort is the larger of the two, because we are tracking the maximum jump seen on that path.
                        if (new_min_effort < visited[newi][newj]) 
                        { //If this new path offers less effort than previously known
                            visited[newi][newj] = new_min_effort;
                            paths.push({new_min_effort, {newi, newj}});
                        }
                    
                }
            }
        }
        return -1;
    }
};
