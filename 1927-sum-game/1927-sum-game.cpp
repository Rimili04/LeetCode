class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int diff = 0;
        int leftQ = 0, rightQ = 0;

        // First half
        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                diff += num[i] - '0';
        }

        // Second half
        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                diff -= num[i] - '0';
        }

        // If equal number of '?', Bob can always mirror Alice.
        if (leftQ == rightQ) {
            return diff != 0;
        }

        // Bob can win only if the difference can be exactly balanced.
        // Multiply by 2 to avoid integer division.
        return 2 * diff != 9 * (rightQ - leftQ);
    }
};