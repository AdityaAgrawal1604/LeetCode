class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        int mini = INT_MAX;
        int ind = -1;
        for(int i = 0;i<n;i++){
            if(r[i]<mini){
                mini = r[i];
                ind = i;
            }
        }
        int add = 0;
        vector<int> ans(n);
        ans[ind]=1;
        for(int i = ind+1;i<n;i++){
            if(r[i-1]<r[i]){
                ans[i]=ans[i-1]+1;
            }else{
                ans[i]=1;
            }
        }
        for(int i = ind-1;i>=0;i--){
            if(r[i+1]<r[i]){
                ans[i]=ans[i+1]+1;
            }else{
                ans[i]=1;
            }
        }
        for(int i = 0;i<n;i++){
            if(i>0){
                if(r[i-1]<r[i]&&ans[i]<=ans[i-1]){
                    ans[i]=ans[i-1]+1;
                }
            }
            if(i<n-1){
                if(r[i+1]<r[i]&&ans[i]<=ans[i+1]){
                    ans[i]=ans[i+1]+1;
                }
            }

        }
        for(int i = n-1;i>=0;i--){
            if(i>0){
                if(r[i-1]<r[i]&&ans[i]<=ans[i-1]){
                    ans[i]=ans[i-1]+1;
                }
            }
            if(i<n-1){
                if(r[i+1]<r[i]&&ans[i]<=ans[i+1]){
                    ans[i]=ans[i+1]+1;
                }
            }       
        }
        for(int i =0 ;i<n;i++){
            add+=ans[i];
            // cout<<ans[i]<<" ";    
        }
        // cout<<endl;
        return add;
    }
};