class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());

        int l = 1;
        int n = piles.size();
        int hi = 1000000000;
        int mid = (l+hi)/2;
        int k = INT_MAX;
        while(l<=hi){
            long long hr = 0;
            for(int i = 0;i<n;i++){
                if(piles[i]%mid==0){
                    hr+=(piles[i]/mid);
                }else{
                    hr+=((piles[i]/mid)+1);
                }
            }
            // cout<<mid<<" "<<hr<<" "<<k<<" "<<endl;
            if(h==hr){
                k = mid;
                hi = mid-1;
            }else if(h<hr){
                l = mid+1;
            }else{
                k = min(mid,k);
                hi = mid-1;
            }
            mid = (l+hi)/2;
        }
        return k;
    }
};