class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        vector<int> indl(n,-1),indr(n,-1);
        for(int i = 0;i<n;i++){
            pair<int,int> p = {nums[i],i};
            if(st.empty()){
                st.push(p);
            }else{
                if(p.first<st.top().first){
                    while(!st.empty()&&p.first<st.top().first){
                        indl[st.top().second]=p.second;
                        st.pop();   
                    }
                }
                st.push(p);
            }
        }
        for(int i = n-1;i>=0;i--){
            pair<int,int> p = {nums[i],i};
            if(st.empty()){
                st.push(p);
            }else{
                if(p.first<st.top().first){
                    while(!st.empty()&&p.first<st.top().first){
                        indr[st.top().second]=p.second;
                        st.pop();   
                    }
                }
                st.push(p);
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(indl[i]==-1){
                if(indr[i]==-1){
                    ans = max(ans,n*nums[i]);
                }else{
                    ans = max(ans,nums[i]*(n-indr[i]-1));
                }
            }else if(indr[i]==-1){
                ans = max(indl[i]*nums[i],ans);
            }else{
                int k = max(indl[i]-indr[i]-1,0)*nums[i];
                ans = max(ans,k);   
            }
        }
        return ans;
    }
};