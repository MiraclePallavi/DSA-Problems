class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

  

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution{
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxdiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= maxdiff)
            ds.unionBySize(i, i + 1);
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            if(ds.findUPar(queries[i][0])==ds.findUPar(queries[i][1])){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};