class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 0;i<n/2;i++){
            int m = i+1;
            string ss = s.substr(0,i+1);
            int j = 0;
            if(n%m) continue;
            int f = 0;
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