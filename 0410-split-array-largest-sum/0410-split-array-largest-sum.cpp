class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int h = 1000000010;
        int mid = (l+h)/2;
        int ans = INT_MAX;
        int zs = 0;
        while(l<=h){
            int k1 = 1;
            int sumi = 0;
            int ism = 0;
            for(int i = 0;i<n;i++){
                if(nums[i]==0)zs++;
                sumi+=nums[i];
                if(sumi==mid){
                    // sumi = 0;
                    // cout<<i<<endl;
                    // cout<<mid<<endl;
                    ism=1;
                    // k1++;
                }else if(sumi>mid){
                    sumi = nums[i];
                    if(sumi==mid){
                        ism=1;
                    }
                    k1++;
                }
            }
            // cout<<mid<<" "<<k1<<endl;
            // if(mid==4){
            //     cout<<k1<<" - "<<ism<<endl;
            // }
            if(k1==k){
                if(!ism){
                    if(sumi>mid){
                        l = mid+1;
                    }else{
                        h = mid-1;  
                    }             
                }else{
                    if(sumi>mid){
                        l = mid+1;
                    }else{
                        ans = min(ans,mid);
                        h = mid-1;                      
                    }
                }

            }else if(k1<k){
                if(sumi>mid){
                    l = mid+1;
                }else{
                    if((k1+zs)>=k&&ism){
                        ans = min(ans,mid);
                        h = mid-1;
                    }else{
                        h = mid-1;
                    }                    
                }

            }else{
                l = mid+1;
            }
            mid = (l+h)/2;
        }
        ans = max(ans,*max_element(nums.begin(),nums.end()));
        return ans;
    }
};