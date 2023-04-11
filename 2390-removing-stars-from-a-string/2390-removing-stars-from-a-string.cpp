class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }else{
                if(st.size()){
                    st.pop();
                }
            }
        }
        string str = "";
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};