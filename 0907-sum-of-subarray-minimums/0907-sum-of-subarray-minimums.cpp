class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nxt(n,n),pre(n,-1);
        stack<pair<int,int>> st;
        for(int i = 0;i<n;i++){
                int ne = arr[i];
                while(!st.empty()&&(ne<=(st.top().first))){
                    nxt[st.top().second] = i;
                    // cout<<st.top().second<<endl;
                    st.pop();
                }
                st.push({ne,i});   
            // cout<<st.size()<<" ";
        }
        // cout<<endl;
        while(!st.empty()) st.pop();
        for(int i = n-1;i>=0;i--){
                int ne = arr[i];
                while(!st.empty()&&(ne<(st.top().first))){
                    pre[st.top().second] = i;
                    st.pop();
                }
                st.push({ne,i});     
        
        }
        while(!st.empty()) st.pop();
        long long ans = 0;
        int mod = 1e9+7;
        // for(int i = 0;i<n;i++){
        //     cout<<pre[i]<<" "<<nxt[i]<<endl;
        // }
        for(int i = 0;i<n;i++){
            long long add = 0;
            add+=arr[i];
            add%=mod;
            add*=(i-pre[i]);
            add%=mod;
            add*=(nxt[i]-i);
            add%=mod;
            ans+=add;
            ans%=mod;
            // cout<<(i-pre[i])<<" "<<(nxt[i]-i)<<" "<<add<<endl;
        }
        return (int)ans;
    }
};