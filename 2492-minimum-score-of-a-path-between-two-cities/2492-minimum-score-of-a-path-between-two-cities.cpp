class Solution {
public:
    int mindis =INT_MAX;
    void dfs(int node, vector<vector<pair<int, int>>>&adj, vector<int>&vis){
        vis[node] = 1;
        for(auto [neighbornode, wt]: adj[node]){
            mindis = min(wt, mindis);
            if(!vis[neighbornode]){
                vis[neighbornode] = 1;
                dfs(neighbornode, adj, vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]-1].push_back({roads[i][1]-1, roads[i][2]});
            adj[roads[i][1]-1].push_back({roads[i][0]-1, roads[i][2]});

        }
        vector<int>vis(n, 0);
        
        dfs(0, adj, vis);
        return mindis;
    }
};