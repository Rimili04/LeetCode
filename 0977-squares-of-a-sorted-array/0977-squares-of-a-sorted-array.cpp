class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int l = 0, r = n - 1, idx = n - 1;

        while (l <= r) {
            if (abs(nums[l]) > abs(nums[r])) {
                ans[idx--] = nums[l] * nums[l];
                l++;
            } else {
                ans[idx--] = nums[r] * nums[r];
                r--;
            }
        }

        return ans;
    }
};