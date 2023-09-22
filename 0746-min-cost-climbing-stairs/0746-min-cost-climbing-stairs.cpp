class Solution {
public:
    int f(int i,vector<int> &dp,vector<int> &c){
        if(i>=c.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=(c[i]+min(f(i+1,dp,c),f(i+2,dp,c)));
    }
    int minCostClimbingStairs(vector<int>& c) {
        int n = c.size();
        vector<int> dp(n,-1);
        return min(f(0,dp,c),f(1,dp,c));
    }
};