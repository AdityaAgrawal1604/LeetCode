class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size();
        int sm = w[0];
        for(int i = 1;i<n;i++){
            // w[i]+=w[i-1];
            sm+=w[i];
        }
        
        int l = *max_element(w.begin(),w.end());
        int h = sm;
        int mid = (l+h)/2;
        int g = INT_MAX;
        // cout<<l<<endl;
        while(l<=h){
            // cout<<mid<<endl;
            int d = 1;
            int cnt = 0;
            for(int i = 0;i<n;i++){
                if((cnt+w[i])>mid){
                    d++;
                    cnt = w[i];
                }else{
                    cnt+=w[i];
                }
            }
            if(d==days){
                g = min(g,mid);
                h = mid-1;
            }else if(d<days){
                g = min(g,mid);
                h = mid-1;
                
            }else{
                l = mid+1;
            }
            mid = (l+h)/2;
        }
        return g;
    }
};