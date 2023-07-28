class Solution {
public:
    int f(int i,int j,int p,vector<int> nums,vector<vector<vector<int>>> &dp){
        if(i>j) return 0;
        if(dp[i][j][p]!=-1) return dp[i][j][p];
        if(p) return dp[i][j][p]=min(-nums[i]+f(i+1,j,0,nums,dp),-nums[j]+f(i,j-1,0,nums,dp));
        return dp[i][j][p]=max(nums[i]+f(i+1,j,1,nums,dp),nums[j]+f(i,j-1,1,nums,dp));
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(2,-1)));
        return (max(nums[0]+f(1,nums.size()-1,1,nums,dp),nums[nums.size()-1]+f(0,nums.size()-2,1,nums,dp))>=0);
    }
};