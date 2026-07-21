class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int ans = 0, i = 0;
        int pre = INT_MIN, mx = 0;

        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) {
                j++;
            }

            int len = j - i;

            if (s[i] == '1') {
                ans += len;
            } else {
                mx = max(mx, pre + len);
                pre = len;
            }

            i = j;
        }

        return ans + mx;
    }
};