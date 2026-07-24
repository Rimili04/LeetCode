class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> cnt;

        for (int x : arr)
            cnt[x]++;

        for (auto &[x, f] : cnt) {
            if (f == 0) continue;

            int want = (x < 0) ? x / 2 : x * 2;

            if (x < 0 && x % 2 != 0)
                return false;

            if (cnt[want] < f)
                return false;

            cnt[want] -= f;
        }

        return true;
    }
};