class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        queue<int> q;
        int n = deck.size();

        for (int i = 0; i < n; i++)
            q.push(i);

        vector<int> ans(n);

        for (int x : deck) {
            int idx = q.front();
            q.pop();
            ans[idx] = x;

            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};