class Solution {
public:
    int countCommas(int n) {
        int ans = 0;

        for (int x = 1000; x <= n; x++) {
            ans += to_string(x).size() / 4;
        }

        return ans;
    }
};