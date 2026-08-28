class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int half = n / 2;

        // Count characters in s
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether a palindrome is possible
        int mid = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                if (mid != -1)
                    return "";

                mid = i;
            }
        }

        // Characters available for the first half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        // Build complete palindrome from its first half
        auto buildPalindrome = [&](const string& first) {
            string ans = first;

            // Middle character for odd length
            if (mid != -1) {
                ans += char('a' + mid);
            }

            // Reverse of first half
            for (int i = half - 1; i >= 0; i--) {
                ans += first[i];
            }

            return ans;
        };

        string targetHalf = target.substr(0, half);

        /*
         * CASE 1:
         * Try using target's first half exactly.
         */
        vector<int> remaining = halfCnt;
        bool possible = true;

        for (char c : targetHalf) {
            remaining[c - 'a']--;

            if (remaining[c - 'a'] < 0) {
                possible = false;
                break;
            }
        }

        if (possible) {
            string candidate = buildPalindrome(targetHalf);

            if (candidate > target) {
                return candidate;
            }
        }

        /*
         * CASE 2:
         * Find the smallest first half strictly greater
         * than targetHalf.
         *
         * We try changing a position from right to left.
         */
        for (int pos = half - 1; pos >= 0; pos--) {

            // Count characters used by targetHalf[0 ... pos-1]
            vector<int> used(26, 0);

            bool validPrefix = true;

            for (int i = 0; i < pos; i++) {
                int c = targetHalf[i] - 'a';

                used[c]++;

                if (used[c] > halfCnt[c]) {
                    validPrefix = false;
                    break;
                }
            }

            if (!validPrefix)
                continue;

            // Try the smallest character greater than target[pos]
            for (int c = targetHalf[pos] - 'a' + 1; c < 26; c++) {

                if (used[c] >= halfCnt[c])
                    continue;

                // Build prefix
                string first = targetHalf.substr(0, pos);

                // Put a larger character at pos
                first += char('a' + c);

                // Remaining characters
                vector<int> left = halfCnt;

                for (int x = 0; x < 26; x++) {
                    left[x] -= used[x];
                }

                left[c]--;

                // Fill remaining positions in sorted order
                for (int x = 0; x < 26; x++) {
                    while (left[x] > 0) {
                        first += char('a' + x);
                        left[x]--;
                    }
                }

                return buildPalindrome(first);
            }
        }

        return "";
    }
};