class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        backtrack(nums, index + 1);

        current.push_back(nums[index]);
        backtrack(nums, index + 1);
        current.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};