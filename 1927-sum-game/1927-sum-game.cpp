class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int diff = 0;
        int leftQ = 0, rightQ = 0;
        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                diff += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                diff -= num[i] - '0';
        }
        if (leftQ == rightQ) {
            return diff != 0;
        }
        return 2 * diff != 9 * (rightQ - leftQ);
    }
};