class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long num = 0;
        char op = '+';

        for (int i = 0; i <= s.size(); i++) {
            if (i < s.size() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            if (i == s.size() || (!isdigit(s[i]) && s[i] != ' ')) {
                if (op == '+') st.push(num);
                else if (op == '-') st.push(-num);
                else if (op == '*') {
                    int t = st.top(); st.pop();
                    st.push(t * num);
                } else {
                    int t = st.top(); st.pop();
                    st.push(t / num);
                }

                op = s[i];
                num = 0;
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};