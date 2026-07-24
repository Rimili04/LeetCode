class Solution {
public:
    string devowel(string s) {
        for (char &c : s) {
            c = tolower(c);
            if (string("aeiou").find(c) != string::npos)
                c = '*';
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vow;

        for (string w : wordlist) {
            string low = w;
            transform(low.begin(), low.end(), low.begin(), ::tolower);
            cap.emplace(low, w);
            vow.emplace(devowel(low), w);
        }

        vector<string> ans;

        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string low = q;
            transform(low.begin(), low.end(), low.begin(), ::tolower);

            if (cap.count(low)) {
                ans.push_back(cap[low]);
                continue;
            }

            string dv = devowel(low);

            if (vow.count(dv))
                ans.push_back(vow[dv]);
            else
                ans.push_back("");
        }

        return ans;
    }
};