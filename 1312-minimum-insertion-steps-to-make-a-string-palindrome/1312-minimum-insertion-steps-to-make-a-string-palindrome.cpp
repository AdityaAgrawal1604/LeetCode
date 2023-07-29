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
        vector<int> dp(n+2,0);
        for(int i = n;i>0;i--){
            vector<int> curr(n+2,0);
            for(int j = 1;j<=n;j++){
                if(i>j) continue;
                if(s[i-1]==s[j-1]) curr[j] = dp[j-1];
                else
                {
                    curr[j] = (1+min(dp[j],curr[j-1]));
                }                
            }
            dp = curr;
        }
        int ans = 0;
        ans = dp[n];
        return ans;
    }
};