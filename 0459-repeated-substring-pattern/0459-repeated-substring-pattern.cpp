class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 0;i<n/2;i++){
            int m = i+1;
            int j = 0;
            map<string,int> mp;
            if(n%m) continue;
            while(j<n){
                mp[s.substr(j,m)]++;
                j+=m;
                if(mp.size()>1) break;
            }
            if(mp.size()==1) return true;
        }
        return false;
    }
};