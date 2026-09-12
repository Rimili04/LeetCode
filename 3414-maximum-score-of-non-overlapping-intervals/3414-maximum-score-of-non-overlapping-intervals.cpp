class Solution {
public:
    using ll = long long;

    struct State {
        ll score = 0;
        vector<int> ids;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;
        return a.ids < b.ids;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<ll, 4>> a;
        for (int i = 0; i < n; i++)
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});

        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            return x[1] < y[1];
        });

        vector<array<State, 5>> dp(n + 1);

        for (int i = 1; i <= n; i++) {
            ll l = a[i - 1][0];
            ll w = a[i - 1][2];
            int idx = a[i - 1][3];

            int p = lower_bound(
                a.begin(), a.begin() + i - 1, l,
                [](const array<ll, 4>& x, ll value) {
                    return x[1] < value;
                }
            ) - a.begin();

            for (int k = 0; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];

                if (k > 0) {
                    State cur = dp[p][k - 1];
                    cur.score += w;

                    auto it = lower_bound(cur.ids.begin(), cur.ids.end(), idx);
                    cur.ids.insert(it, idx);

                    if (better(cur, dp[i][k]))
                        dp[i][k] = cur;
                }
            }
        }

        State ans = dp[n][0];

        for (int k = 1; k <= 4; k++)
            if (better(dp[n][k], ans))
                ans = dp[n][k];

        return ans.ids;
    }
};