class Solution {
public:
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
        return dp[n];
    }
};