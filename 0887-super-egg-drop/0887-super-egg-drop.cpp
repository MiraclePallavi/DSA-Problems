class Solution {
public:
    int minmoves(int floors, int eggs, vector<vector<int>>& dp) {
        if (floors == 0 || floors == 1) return floors;
        if (eggs == 1) return floors;

        if (dp[floors][eggs] != -1)
            return dp[floors][eggs];

        int l = 1, r = floors;

        while (l < r) {
            int mid = l + (r - l) / 2;

            int breaks = minmoves(mid - 1, eggs - 1, dp);
            int survives = minmoves(floors - mid, eggs, dp);

            if (breaks < survives)
                l = mid + 1;
            else
                r = mid;
        }

        int breaks = minmoves(l - 1, eggs - 1, dp);
        int survives = minmoves(floors - l, eggs, dp);

        return dp[floors][eggs] =
            1 + max(breaks, survives);
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, -1));

        return minmoves(n, k, dp);
    }
};