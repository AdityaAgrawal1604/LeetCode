class Solution {
public:
    int f(int i,int prev,vector<int> nums,vector<vector<int>> &dp){
        if(i<0){
            return 0;
        }
        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int take = 0;
        if(nums[i]<nums[prev]){
            take = 1+f(i-1,i,nums,dp);
        }
        int notTake = f(i-1,prev,nums,dp);
        return max(take,notTake);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1e9);
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = 0;i<n;i++){
            for(int j = 1;j<=n;j++){
                if(i == 0){
                    if(nums[i]<nums[j]){
                        dp[i][j] = 1;
                    }
                }else{
                    int take = 0;
                    if(nums[i]<nums[j]){
                        take = 1+dp[i-1][i];
                    }
                    int notTake = dp[i-1][j];
                    dp[i][j] = max(take,notTake);                    
                }

            }
        }
        return dp[n-1][n];
    }
};