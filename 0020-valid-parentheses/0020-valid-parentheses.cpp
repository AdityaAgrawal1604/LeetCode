class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]=='('){
                st.push(')');
            }
            if(s[i]=='['){
                st.push(']');
            }
            if(s[i]=='{'){
                st.push('}');
            }
            if(s[i]==')'||s[i]==']'||s[i]=='}'){
                if(!st.empty()&&st.top()==s[i]){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.size()){
            return false;
        }
        return true;
    }
};