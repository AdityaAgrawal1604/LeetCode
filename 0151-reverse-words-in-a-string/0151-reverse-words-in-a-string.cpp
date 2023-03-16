class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string t = "";
        string ans = "";
        for(int i = 0;i<n;i++){
            if(s[i]==' '){
                if(t!=""){
                    if(ans==""){
                        ans = t;
                    }else{
                        ans = t+" "+ans;
                    }
                    t = "";
                }
            }else{
                t+=s[i];
            }
        }
        if(t!=""){
            if(ans==""){
                ans = t;
            }else{
                ans = t+" "+ans;
            }
            t = "";
        }
        return ans;
    }
};