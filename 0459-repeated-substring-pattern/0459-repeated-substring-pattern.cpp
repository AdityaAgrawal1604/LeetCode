class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size(),m,j,f;
        string ss;
        for(int i = 0;i<n/2;i++){
            m = i+1;
            ss = s.substr(0,i+1);
            j = 0;
            if(n%m) continue;
            f = 0;
            while(j<n){
                if(s.substr(j,m)!=ss){
                    f = 1;
                    break;
                }
                j+=m;
            }
            if(!f) return true;
        }
        return false;
    }
};