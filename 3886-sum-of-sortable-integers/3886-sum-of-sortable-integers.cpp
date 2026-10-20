class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;
            bool ok = true;
            int prevMax = 0; // nums[i] >= 1
            for (int s = 0; s < n && ok; s += k) {
                int mn = INT_MAX, mx = INT_MIN, desc = 0;
                for (int j = 0; j < k; j++) {
                    int cur = nums[s + j];
                    int nxt = nums[s + (j + 1) % k];
                    if (cur > nxt) desc++;
                    mn = min(mn, cur);
                    mx = max(mx, cur);
                }
                if (desc > 1 || mn < prevMax) ok = false;
                prevMax = mx;
            }
            if (ok) ans += k;
        }
        return (int)ans;
    }
};