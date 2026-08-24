class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<long long> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // dp = maximum score difference for the current state
        long long dp = prefix[n - 1];

        // We can choose a prefix ending at i (i >= 1)
        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, prefix[i] - dp);
        }

        return dp;
    }
};