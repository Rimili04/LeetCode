class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        string ans = "";

        do {
            int h = arr[0] * 10 + arr[1];
            int m = arr[2] * 10 + arr[3];

            if (h < 24 && m < 60) {
                string cur;
                cur += char('0' + arr[0]);
                cur += char('0' + arr[1]);
                cur += ':';
                cur += char('0' + arr[2]);
                cur += char('0' + arr[3]);

                ans = max(ans, cur);
            }
        } while (next_permutation(arr.begin(), arr.end()));

        return ans;
    }
};