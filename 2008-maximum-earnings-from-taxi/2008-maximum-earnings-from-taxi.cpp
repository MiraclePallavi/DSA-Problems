class Solution {
public:
    long long solve(int ind, int rsize, vector<vector<int>>& rides,
                    vector<long long>& dp) {

        if (ind >= rsize)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int curStart = rides[ind][0];
        int curEnd = rides[ind][1];
        int tip = rides[ind][2];

        vector<int> target = {curEnd, 0, 0};

        int nextInd = lower_bound(rides.begin() + ind + 1,
                                  rides.end(),
                                  target) - rides.begin();

        long long take = (curEnd - curStart + tip) +
                         solve(nextInd, rsize, rides, dp);

        long long notTake = solve(ind + 1, rsize, rides, dp);

        return dp[ind] = max(take, notTake);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        sort(rides.begin(), rides.end());

        int rsize = rides.size();
        vector<long long> dp(rsize, -1);

        return solve(0, rsize, rides, dp);
    }
};