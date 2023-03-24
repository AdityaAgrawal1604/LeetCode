class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // reverse(nums.begin(),nums.end());
        // nums.push_back(0);
        // reverse(nums.begin(),nums.end());
        int n = nums.size();
        if(n==1&&nums[0]==0){
            return 0;
        }
        int lst = 0;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                maxi=0;
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i]!=0){
                lst = i;
                break;
            }
        }
        for(int i = lst;i<n;i++){
            if(nums[i]==0||(i==n-1)){
                if(i==n-1&&nums[i]!=0){
                    i++;
                }
                int neg = 0;
                for(int j = lst;j<i;j++){
                    if(nums[j]<0){
                        neg++;
                    }
                }
                // cout<<neg<<endl;
                if(neg&1){
                    
                    int fst = -1;
                    int lt = -1;
                    for(int j = lst;j<i;j++){
                        if(nums[j]<0){
                            if(fst==-1){
                                fst = j;
                            }
                            lt = j;
                        }
                    }
                    // cout<<i<<" "<<lt<<endl;
                    if(fst==-1&&(i-lst)==1){
                        maxi=max(maxi,nums[lst]);
                        lst = i+1;
                        continue;
                    }
                    if((i-lst)==1){
                        maxi = max(maxi,nums[lst]);
                        lst = i+1;
                        continue;
                    }
                    int prod1 = 1;
                    for(int j = fst+1;j<i;j++){
                        prod1*=nums[j];
                    }
                    int prod2 = 1;
                    for(int j = lst;j<lt;j++){
                        prod2*=nums[j];
                    }
                    maxi = max(maxi,max(prod1,prod2));
                }else{
                    // cout<<i<<endl;
                    int prod = 1;
                    for(int j = lst;j<i;j++){
                        prod*=nums[j];
                    }
                    maxi = max(maxi,prod);
                }
                lst = i+1;
            }
        }
        return maxi;
    }
};