class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int k = 0;
        for(int i = 0;i<n;i++){
            if(s[i]!=' '){
                int l = i;
                while(i<n&&s[i]!=' '){
                    i++;
                }
                k = i-l;
            }
        }
        return k;
    }
};