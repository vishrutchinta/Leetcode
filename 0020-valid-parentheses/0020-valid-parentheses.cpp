
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // Handle closing brackets
            else {
                // If stack is empty, no matching open bracket exists
                if (st.empty()) return false;

                char top = st.top();
                // Check for matching pairs
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false; // Mismatched brackets
                }
            }
        }

        // Return true only if all brackets were properly matched and popped
        return st.empty();
    }
};