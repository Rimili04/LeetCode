class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<string, int> seen;

        while (n > 0) {
            string key;
            for (int x : cells)
                key += char(x + '0');

            if (seen.count(key)) {
                int cycle = seen[key] - n;
                n %= cycle;
            }

            seen[key] = n;

            if (n > 0) {
                n--;
                vector<int> next(8, 0);

                for (int i = 1; i < 7; i++)
                    next[i] = (cells[i - 1] == cells[i + 1]);

                cells = next;
            }
        }

        return cells;
    }
};