class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        dist[0][0]= grid[0][0];
        queue<pair<int, int>>q;
        q.push({0, 0});
        int dirs[5] = {-1, 0, 1, 0, -1};
        while(!q.empty()){
            auto [curRow, curCol] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nextRow = curRow+dirs[i];
                int nextCol = curCol+dirs[i+1];
                if(nextRow<n && nextRow>=0 && nextCol<m && nextCol>=0 && dist[nextRow][nextCol]>dist[curRow][curCol]+grid[nextRow][nextCol]){
                    dist[nextRow][nextCol]=dist[curRow][curCol]+grid[nextRow][nextCol];
                    q.push({nextRow, nextCol});
                }
            }
        }
        return dist[n-1][m-1]<health;
    }
};