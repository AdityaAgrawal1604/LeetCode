class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<vector<int>> v;
        long long ans = 0;
        int i = 0;
        int n = nums.size();
        vector<int> t;
        
        while(i<n){
            
            if(nums[i]<minK||nums[i]>maxK){
                // cout<<i<<" "<<n<<endl;
                if(t.size()){
                    v.push_back(t);
                    t.clear();
                }
            }else{
                t.push_back(nums[i]);
            }
            i++;
        }
        if(t.size()){
            v.push_back(t);
        }
        for(auto x:v){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
            int k = x.size();
            vector<int> os(x.size(),0),fs(x.size(),0);
            // cout<<k<<endl;
            for(int  j = k-1;j>=0;j--){
                if(j==k-1){
                    if(x[j]==minK){
                        os[j]=j;
                    }else{
                        os[j]=-1;
                    }
                    if(x[j]==maxK){
                        fs[j]=j;
                    }else{
                        fs[j]=-1;
                    }
                    continue;
                }
                if(x[j]==minK){
                    os[j]=j;
                }else{
                    os[j]=os[j+1];
                }
                if(x[j]==maxK){
                    fs[j]=j;
                }else{
                    fs[j]=fs[j+1];
                }
            }
            for(int j = 0;j<k;j++){
                if(x[j]==minK){
                    if(fs[j]!=-1){
                        ans+=(k-fs[j]);
                    }
                    
                }else if(x[j]==maxK){
                    if(os[j]!=-1){
                        ans+=(k-os[j]);
                    }
                    
                }else{
                    if(fs[j]!=-1&&os[j]!=-1){
                        ans+=(k-max(os[j],fs[j]));
                    }
                }
            }
        }
        return ans;
    }
};