class Solution {
public:
    using ll = long long;

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;

        for (int dr = -n + 1; dr < n; dr++) {
            for (int dc = -n + 1; dc < n; dc++) {
                int cur = 0;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int x = i + dr;
                        int y = j + dc;

                        if (x >= 0 && x < n && y >= 0 && y < n)
                            cur += img1[i][j] & img2[x][y];
                    }
                }

                ans = max(ans, cur);
            }
        }

        return ans;
    }
};