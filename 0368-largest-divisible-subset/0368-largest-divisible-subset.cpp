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
                    // f = 1;
                    pos[i]=max(pos[i],pos[mp[j]-1]+1);
                    // break;
                }
                if((nums[i]%j==0)&&(mp[nums[i]/j])&&((j)!=1)){
                    // f = 1;
                    pos[i]=max(pos[i],pos[mp[nums[i]/j]-1]+1);
                    // break;
                }
            }
            // if(f) continue;
            // cout<<"x "<<x<<endl;
            // int temp = 1;
            // for(int j = (i+1);j<n;j++){
            //     if((nums[j]%x)==0){
            //         temp++;
            //         x = nums[j];
            //         cout<<x<<endl;
            //     }
            // }
            // if(temp>maxi){
            //     maxi = temp;
            //     x = nums[i];
            //     ans.clear();
            //     ans.push_back(nums[i]);
            //     for(int j = (i+1);j<n;j++){
            //         if((nums[j]%x)==0){
            //             x = nums[j];
            //             ans.push_back(x);
            //         }
            //     }
            // }
            // cout<<temp<<endl;
        }
        int x = -1;
        for(int i = 0;i<n;i++){
            if(pos[i]>maxi){
                maxi = pos[i];
                x = nums[i];
            }
            // cout<<pos[i]<<" ";
        }
        // cout<<endl;
        for(int i = (n-1);i>=0;i--){
            // cout<<i<<" "<<maxi<<" "<<x<<" "<<nums[i]<<endl;
            if(((pos[i]==maxi))){
                if(x%nums[i]) continue;
                x = nums[i];
                ans.push_back(x);
                maxi--;
            }
        }
        // cout<<maxi<<endl;
        return ans;
    }
};