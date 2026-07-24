class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flip(n, 0);

        int cur = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            if (i >= k)
                cur ^= flip[i - k];

            if ((nums[i] ^ cur) == 0) {
                if (i + k > n)
                    return -1;

                ans++;
                cur ^= 1;
                flip[i] = 1;
            }
        }

        return ans;
    }
};