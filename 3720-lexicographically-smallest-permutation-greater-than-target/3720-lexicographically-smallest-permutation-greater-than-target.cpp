class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Count characters available in s
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        string ans = "";

        for (int i = 0; i < n; i++) {

            // Try to keep target[i] equal
            if (cnt[target[i] - 'a'] > 0) {
                cnt[target[i] - 'a']--;
                ans += target[i];
                continue;
            }

            // Cannot match target[i].
            // Try the smallest character greater than target[i].
            int bigger = -1;

            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger != -1) {
                ans += char('a' + bigger);
                cnt[bigger]--;

                // Fill the remaining positions with smallest characters.
                for (int c = 0; c < 26; c++) {
                    while (cnt[c] > 0) {
                        ans += char('a' + c);
                        cnt[c]--;
                    }
                }

                return ans;
            }

            // We cannot make this position equal or greater.
            // We need to go back and make an earlier position bigger.
            break;
        }

        // Backtrack to find the rightmost position
        // where we can increase the character.
        cnt.assign(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // At each position, try matching target exactly.
        for (int i = 0; i < n; i++) {
            if (cnt[target[i] - 'a'] == 0)
                break;

            cnt[target[i] - 'a']--;
        }

        // Easier and safer approach:
        // Try every possible pivot from right to left.
        for (int pivot = n - 1; pivot >= 0; pivot--) {

            cnt.assign(26, 0);
            bool possible = true;

            // Characters used before pivot must equal target.
            for (int i = 0; i < pivot; i++) {
                int x = target[i] - 'a';

                if (cnt[x] == 0) {
                    // Rebuild count properly below.
                    possible = false;
                    break;
                }
                cnt[x]--;
            }

            // Instead of relying on the above count, rebuild it.
            cnt.assign(26, 0);
            for (char c : s)
                cnt[c - 'a']++;

            possible = true;

            for (int i = 0; i < pivot; i++) {
                int x = target[i] - 'a';

                if (cnt[x] == 0) {
                    possible = false;
                    break;
                }

                cnt[x]--;
            }

            if (!possible)
                continue;

            // Find the smallest character greater than target[pivot].
            int x = target[pivot] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string res = target.substr(0, pivot);
                    res += char('a' + c);
                    cnt[c]--;

                    // Fill remaining positions in sorted order.
                    for (int ch = 0; ch < 26; ch++) {
                        while (cnt[ch] > 0) {
                            res += char('a' + ch);
                            cnt[ch]--;
                        }
                    }

                    return res;
                }
            }
        }

        return "";
    }
};