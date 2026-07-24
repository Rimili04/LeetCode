class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            if (st.empty() || nums[i] < nums[st.top()])
                st.push(i);
        }

        int ans = 0;

        for (int j = nums.size() - 1; j >= 0; j--) {
            while (!st.empty() && nums[j] >= nums[st.top()]) {
                ans = max(ans, j - st.top());
                st.pop();
            }
        }

        return ans;
    }
};