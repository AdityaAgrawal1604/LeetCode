const int m = 1e9+7; 
class Solution {
public:
    long long binexpo(int a,int b){
        if(b==0){
            return 1;
        }
        long long k = (binexpo(a,b/2));
        k = (k*k)%m;
        if(b&1){
            k*=a;
            k%=m;
        }
        return k;
    }
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int j;
        for(j = 0;j<n;j++){
            if(nums[0]+nums[j]>target){
                break;
            }
        }
        j--;
        int i = 0;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans+=(binexpo(2,(j-i))-1);
                if(nums[i]*2<=target){
                    ans++;
                }
                ans%=m;
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};