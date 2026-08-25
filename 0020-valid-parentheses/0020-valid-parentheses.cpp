
class Solution {
public:
    bool isValid(std::string s) {
        stack<char> st;
        for(int i=0;i<=s.size()-1;i++){
            if(s[i] =='{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }
            else if(st.empty()){
                return false;
            }
            else{
                if(s[i] == '}' && st.top() == '{'){
                    st.pop();
                }
                else if(s[i] == ']' && st.top() == '['){
                    st.pop();
                }
                else if(s[i] == ')' && st.top() == '('){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
                
            }
            
    }
    if(st.empty()){
        return true;

    }
    else{
        return false;
    }
}};