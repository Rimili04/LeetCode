class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(2048, false);
        vector<bool> possible(2048, false);

        for (int x : nums)
            seen[x] = true;

        for (int x = 0; x < 2048; x++) {
            if (!seen[x]) continue;

            for (int y = 0; y < 2048; y++) {
                if (seen[y])
                    possible[x ^ y] = true;
            }
        }

        vector<bool> result(2048, false);

        for (int x = 0; x < 2048; x++) {
            if (!possible[x]) continue;

            for (int y : nums)
                result[x ^ y] = true;
        }

        return count(result.begin(), result.end(), true);
    }
};