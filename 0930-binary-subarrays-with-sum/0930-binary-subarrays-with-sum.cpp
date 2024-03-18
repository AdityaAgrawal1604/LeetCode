class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int g) {
        // reverse(nums.begin(),nums.end());
        // nums.push_back(0);
        // reverse(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        for(int i = 0;i<n;i++){
            int f = 0;
            if(i!=0){
                if(nums[i-1]==nums[i]) f = 1;
            }else{
                if(!nums[i]) f = 1;
            }
            int l,h;
            if(f){
                l = lower_bound(nums.begin()+i,nums.end(),nums[i]+g)-nums.begin();
                h = upper_bound(nums.begin(),nums.end(),nums[i]+g)-nums.begin();
                ans+=(h-l);
            }else{
                l = lower_bound(nums.begin()+i,nums.end(),nums[i]-1+g)-nums.begin();
                h = upper_bound(nums.begin(),nums.end(),nums[i]-1+g)-nums.begin();
                ans+=(h-l);
            }
            // cout<<l<<" "<<h<<endl;
        }
        return ans;
        
    }
};