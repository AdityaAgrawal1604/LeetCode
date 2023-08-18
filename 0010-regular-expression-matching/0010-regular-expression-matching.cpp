class Solution {
public:
    int f(int i,int j,string &s,string &p,vector<vector<int>> &dp){
        if(j<0){
            if(i>=0) return 0;
            return 1;
        }
        if(i<0){
            for(int k = j;k>=0;k-=2){
                if(p[k]!='*') return 0;
            }
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if((s[i]==p[j])||(p[j]=='.')) return dp[i][j] = f(i-1,j-1,s,p,dp);
        if(p[j]=='*'){ 
            int f1 = f(i,j-2,s,p,dp);
            int f2 = 0;
            if((s[i]==p[j-1])||(p[j-1]=='.')) f2 = f(i-1,j,s,p,dp);
            return dp[i][j] = (f2||f1);
        }
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};