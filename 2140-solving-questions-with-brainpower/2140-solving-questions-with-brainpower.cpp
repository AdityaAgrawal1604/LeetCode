class Solution {
public:
    long long f(int i,vector<vector<int>> &q,vector<long long> dp,int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        long long take = q[i][0]+f(i+q[i][1]+1,q,dp,n);
        long long notTake = f(i+1,q,dp,n);
        return dp[i] = max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n+100100,0);
        for(int i = n-1;i>=0;i--){
            long long take = q[i][0]+dp[i+q[i][1]+1];
            long long notTake = dp[i+1];
            dp[i] = max(take,notTake);
        }
        long long ans = dp[0];
        return ans;
    }
};