class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen, ans;
        int k = 0;

        for (int num : nums) {
            if (num == -1) {
                k++;
                if (k <= seen.size())
                    ans.push_back(seen[k - 1]);
                else
                    ans.push_back(-1);
            } else {
                seen.insert(seen.begin(), num);
                k = 0;
            }
        }

        return ans;
    }
};