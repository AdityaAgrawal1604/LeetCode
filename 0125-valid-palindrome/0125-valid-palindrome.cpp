class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]>='A'&&s[i]<='Z'){
                s1+=(s[i]-'A'+'a');
            }else if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')){
                s1+=s[i];
            }
        }
        int i = 0;
        int j = s1.size()-1;
        while(i<j){
            if(s1[i]!=s1[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};