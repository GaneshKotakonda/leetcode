class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string str = "";

        for (char ch : s) {
            if (ch == '(') {
                // Save everything before this parenthesis
                st.push(str);
                str = "";
            }
            else if (ch == ')') {
                // Reverse the current parentheses content
                reverse(str.begin(), str.end());

                // Add the string before '('
                str = st.top() + str;
                st.pop();
            }
            else {
                str += ch;
            }
        }

        return str;
    }
};