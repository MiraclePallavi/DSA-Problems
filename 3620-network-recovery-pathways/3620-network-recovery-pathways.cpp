class Solution {
public:
    long long minScore(long long mid, vector<vector<pair<int, int>>>& adj, int v, vector<bool>& online) {
        vector<long long> dist(v, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto [next, wt] : adj[node]) {
                if (wt < mid) continue;

                if (dist[next] > dist[node] + 1LL * wt && online[next]) {
                    dist[next] = dist[node] + 1LL * wt;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist[v - 1];
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        long long maxcost = LLONG_MIN, mincost = 0;
        int n = edges.size();
        int v = online.size();

        for (int i = 0; i < n; i++) {
            maxcost = max(maxcost, 1LL * edges[i][2]);
        }

        long long ans = -1;

        vector<vector<pair<int, int>>> adj(v);
        for (int i = 0; i < n; i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        while (maxcost >= mincost) {
            long long mid = mincost + (maxcost - mincost) / 2;

            if (minScore(mid, adj, v, online) <= k) {
                ans = mid;
                mincost = mid + 1;
            } else {
                maxcost = mid - 1;
            }
        }

        return (int)ans;
    }
};