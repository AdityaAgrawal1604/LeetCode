class Solution {
public:
    int f(int i,int j,string s,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]) return dp[i][j] = f(i+1,j-1,s,dp);
        else
        {
            return dp[i][j] = (1+min(f(i+1,j,s,dp),f(i,j-1,s,dp)));
        }
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i = n;i>0;i--){
            for(int j = 1;j<=n;j++){
                if(i>j) continue;
                if(s[i-1]==s[j-1]) dp[i][j] = dp[i+1][j-1];
                else
                {
                    dp[i][j] = (1+min(dp[i+1][j],dp[i][j-1]));
                }                
            }
        }
        int ans = 0;
        ans = dp[1][n];
        return ans;
    }
};