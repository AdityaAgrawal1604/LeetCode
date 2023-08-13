class Solution {
public:
    int f(int i,vector<int>& nums,vector<int> &dp){
        if(i<0) return 1;
        if(dp[i]!=-1) return dp[i];
        int cond1=0,cond2=0,cond3=0;
        if(i>=1){
            if(nums[i]==nums[i-1]) cond1 = f(i-2,nums,dp);   
        }
        if(i>=2){
            if(nums[i]==nums[i-1]&&nums[i]==nums[i-2]) cond2 = f(i-3,nums,dp);
            if(nums[i]==(nums[i-1]+1)&&(nums[i-1]==(nums[i-2]+1))) cond3 = f(i-3,nums,dp);
        }
        return dp[i]=(cond1||cond2||cond3);
        
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
};