class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur;

        path += '/';

        for(char c : path) {
            if(c == '/') {
                if(cur == "" || cur == ".") {
                }
                else if(cur == "..") {
                    if(!st.empty()) st.pop_back();
                }
                else {
                    st.push_back(cur);
                }
                cur.clear();
            }
            else {
                cur += c;
            }
        }

        if(st.empty()) return "/";

        string ans;
        for(string &dir : st)
            ans += "/" + dir;

        return ans;
    }
};