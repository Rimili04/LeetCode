class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = smallest index j in word2 such that
        // word2[j...] can be matched exactly using word1[i...]
        vector<int> suf(n + 1, m);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = j + 1;
        }

        vector<int> ans;
        int j2 = 0;
        bool mismatchUsed = false;

        for (int i = 0; i < n && j2 < m; i++) {

            // Exact match
            if (word1[i] == word2[j2]) {
                ans.push_back(i);
                j2++;
            }

            // Use the one allowed mismatch
            else if (!mismatchUsed && suf[i + 1] <= j2 + 1) {
                ans.push_back(i);
                j2++;
                mismatchUsed = true;
            }
        }

        if (j2 == m)
            return ans;

        return {};
    }
};