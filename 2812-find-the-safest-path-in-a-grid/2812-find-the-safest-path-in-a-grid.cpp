class UnionFind {
public:
    vector<int> parent;  // Parent array for union-find structure
    int componentCount;  // Number of connected components

    // Initialize union-find with n elements
    UnionFind(int n) : componentCount(n), parent(n) {
        // Initially, each element is its own parent
        iota(parent.begin(), parent.end(), 0);
    }

    // Unite two elements, returns true if they were in different components
    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        // Already in the same component
        if (rootA == rootB) {
            return false;
        }

        // Connect rootA to rootB
        parent[rootA] = rootB;
        componentCount--;
        return true;
    }

    // Find root of element x with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
};
class Solution {
public:

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])return 0;
        queue<pair<int, int>>q;
        vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i, j});
                    dist[i][j] =0;
                }
            }
        }
        int directions[5] = {-1, 0, 1, 0, -1};
        while(!q.empty()){
            auto [currow, curcol] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nextRow = currow+directions[i];
                int nextcol = curcol+directions[i+1];
                if(nextRow>=0 && nextRow<n && nextcol>=0 && nextcol<n && dist[nextRow][nextcol]==INT_MAX){
                    dist[nextRow][nextcol] =dist[currow][curcol]+1;
                    q.push({nextRow,nextcol });
                }
            }
        }
        vector<tuple<int, int, int>>cellWithDistance;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cellWithDistance.emplace_back(dist[i][j], i, j);
            }
        }
        sort( cellWithDistance.rbegin(),  cellWithDistance.rend());
    UnionFind uf(n*n);
    for(auto [currdist, row, col]: cellWithDistance){
        for(int i=0;i<4;i++){
            int adjrow = row+directions[i];
            int adjcol = col+directions[i+1];
            if(adjrow<n && adjcol>=0 && adjrow>=0 && adjcol<n && dist[adjrow][adjcol]>=currdist){
                uf.unite(row*n+col, adjrow*n+adjcol);
            }
        }
        if(uf.find(0)==uf.find(n*n-1)){
            return currdist;
        }
    }
    return 0;
    }
};