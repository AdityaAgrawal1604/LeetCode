class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 0;i<n;i++){
            mp[nums[i]]=i+1;
        }
        vector<int> pos(n,1);
        int maxi = 0;
        for(int i = 0;i<n;i++){
            int x = nums[i];
            int f = 0;
            for(int j=1;(j*j)<=nums[i];j++){
                if(((nums[i]%j==0)&&(mp[j])&&((nums[i]/j)!=1))){
                    pos[i]=max(pos[i],pos[mp[j]-1]+1);
                }
                if((nums[i]%j==0)&&(mp[nums[i]/j])&&((j)!=1)){
                    pos[i]=max(pos[i],pos[mp[nums[i]/j]-1]+1);
                }
            }
        }
        int x = -1;
        for(int i = 0;i<n;i++){
            if(pos[i]>maxi){
                maxi = pos[i];
                x = nums[i];
            }
        }
        for(int i = (n-1);i>=0;i--){
            if(((pos[i]==maxi))){
                if(x%nums[i]) continue;
                x = nums[i];
                ans.push_back(x);
                maxi--;
            }
        }
        return ans;
    }
};