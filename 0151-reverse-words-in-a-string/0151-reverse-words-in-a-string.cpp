class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> v;
        string st = "";
        for(int i = 0;i<n;i++){
            if(s[i]==' '){
                if(st.size()){
                    v.push_back(st);
                    st = "";
                }
            }else{
                st+=s[i];
            }
        }
        if(st.size()){
            v.push_back(st);
        }
        reverse(v.begin(),v.end());
        st = "";
        for(int i = 0;i<v.size()-1;i++){
            st+=v[i];
            st+=" ";
        }
        st+=v[v.size()-1];
        return st;
    }
};