class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char str : s) {
            if (str == '(' || str == '{' || str == '[') {
                st.push(str);
            }
            else {
                if (st.empty())
                return false;
                if (str == ')' && st.top() != '(' ||
                    str == '}' && st.top() != '{' ||
                    str == ']' && st.top() != '[')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};