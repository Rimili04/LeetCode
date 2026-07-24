class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;

        for (int x : nums) {
            sum = ((sum + x) % k + k) % k;
            ans += mp[sum];
            mp[sum]++;
        }

        return ans;
    }
};