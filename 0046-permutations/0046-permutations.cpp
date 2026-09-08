class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        function<void(int)> backtrack = [&](int index) {
            if (index == nums.size()) {
                ans.push_back(nums);
                return;
            }

            for (int i = index; i < nums.size(); i++) {
                swap(nums[index], nums[i]);
                backtrack(index + 1);
                swap(nums[index], nums[i]);
            }
        };

        backtrack(0);
        return ans;
    }
};