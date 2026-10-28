class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<unordered_set<int>> dp(m * n);

        dp[0].insert(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;

                if (i == 0 && j == 0) continue;

                if (i > 0) {
                    for (int x : dp[(i - 1) * n + j])
                        dp[idx].insert(x ^ grid[i][j]);
                }

                if (j > 0) {
                    for (int x : dp[i * n + j - 1])
                        dp[idx].insert(x ^ grid[i][j]);
                }
            }
        }

        return *min_element(dp[m * n - 1].begin(),
                            dp[m * n - 1].end());
    }
};