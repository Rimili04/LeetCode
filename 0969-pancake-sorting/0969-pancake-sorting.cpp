class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();

        for (int x = n; x > 1; x--) {
            int idx = max_element(arr.begin(), arr.begin() + x) - arr.begin();

            if (idx == x - 1)
                continue;

            if (idx > 0) {
                reverse(arr.begin(), arr.begin() + idx + 1);
                ans.push_back(idx + 1);
            }

            reverse(arr.begin(), arr.begin() + x);
            ans.push_back(x);
        }

        return ans;
    }
};