class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string half = "", mid = "";

        for (int i = 0; i < 26; i++) {
            half.append(freq[i] / 2, char('a' + i));
            if (freq[i] % 2)
                mid = char('a' + i);
        }

        string rev = half;
        reverse(rev.begin(), rev.end());

        return half + mid + rev;
    }
};