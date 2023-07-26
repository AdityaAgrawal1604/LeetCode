class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hr) {
        int l = 1;
        int h = 10000000;
        int mid = (l+h)/2;
        int ans = INT_MAX;
        int n = dist.size();
        while(l<=h){
            double cnt = 0;
            for(int i = 0;i<n-1;i++){
                cnt+=(((dist[i]+mid-1))/mid);
            }
            cnt+=(dist[n-1]*1.0)/mid;
            if(cnt==hr){
                ans = min(ans,mid);
                h = mid-1;
            }else if(cnt<hr){
                ans = min(ans,mid);
                h = mid-1;
            }else{
                l = mid+1;
            }
            mid = (l+h)/2;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};