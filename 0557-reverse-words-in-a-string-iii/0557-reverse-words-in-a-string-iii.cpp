class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        for(int i = 0;i<s.size();i++){
            if(s[i]==' '){
                ans+=s[i];
            }else{
                string x = "";
                while(i<s.size()&&(s[i]!=' ')){
                    x+=s[i];
                    i++;
                }
                reverse(x.begin(),x.end());
                ans+=x;
                i--;
            }
        }
        return ans;
    }
};