class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int total = m * n;

        k %= total;

        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < total; i++) {
            int ni = (i + k) % total;

            ans[ni / n][ni % n] = grid[i / n][i % n];
        }

        return ans;
    }
};