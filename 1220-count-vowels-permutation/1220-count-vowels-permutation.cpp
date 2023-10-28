// int ct;
int mod = 1e9+7;
class Solution {
public:
    long long f(int n,int j,vector<vector<int>> &dp){
        if(n==0) {
            // cout<<j<<endl;
            // ct++;
            return 1;
        };
        if(dp[n][j]!=-1) return dp[n][j];
        long long i1 = 0;
        if(j==0){
            i1+=(f(n-1,1,dp));
        }else if(j==1){
            i1+=((f(n-1,0,dp)%mod)+(f(n-1,2,dp)%mod));
        }else if(j==2){
            i1+=(1ll*(f(n-1,0,dp)%mod)+(f(n-1,1,dp)%mod)+(f(n-1,3,dp)%mod)+(f(n-1,4,dp)%mod));
        }else if(j==3){
            i1+=(1ll*(f(n-1,2,dp)%mod)+(f(n-1,4,dp)%mod));
        }else{
            i1+=(f(n-1,0,dp)%mod);
        }
        i1%=mod;
        return dp[n][j]=i1;
    }
    int countVowelPermutation(int n) {
        // ct = 0;
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        long long ans = ((f(n-1,0,dp)%mod)+(f(n-1,1,dp)%mod)+(f(n-1,2,dp)%mod)+(f(n-1,3,dp)%mod)+(f(n-1,4,dp)%mod));
        ans%=mod;
        return ans;
    }
};