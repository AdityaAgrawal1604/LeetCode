class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int st = -1;
        int en = 0;
        int k = f.size();
        for(int i = 0;i<k;i++){
            if(f[i]==1){
                if(st==-1){
                    st = en;
                }
                en = 0;
            }else{
                en++;
            }
        }
        if(st==-1){
            return (n<=((k+1)/2));
        }
        int ans = 0;
        ans+=((st)/2);
        ans+=((en)/2);
        vector<int> v;
        int z = 0;
        for(int i = st;i<(k-en);i++){
            if(f[i]==1){
                if(z){
                    v.push_back(z);
                }
                z = 0;
            }else{
                z++;
            }
        }
        
        for(auto x:v){
            x-=2;
            ans+=(x+1)/2;
        }
        // cout<<ans<<endl;
        return (n<=ans);
        
    }
};