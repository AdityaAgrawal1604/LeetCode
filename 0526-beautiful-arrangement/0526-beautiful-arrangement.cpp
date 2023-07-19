class Solution {
public:
    int f(int i,int mask,int n,vector<vector<int>> &dp){
        if(i==n) return 1;
        if(dp[i][mask]!=-1) return dp[i][mask];
        int ans = 0;
        for(int j = 0;j<n;j++){
            if((!((mask>>j)&1))&&(((i+1)%(j+1)==0)||((j+1)%(i+1))==0)){
                ans+=f(i+1,mask|(1<<j),n,dp);
            }
        }
        return dp[i][mask]=ans;
    }
    int countArrangement(int n) {
        vector<vector<int>> dp(n,vector<int>((1<<n),-1));
        return f(0,0,n,dp);
    }
};