#define ll long long
vector<ll> pr(5000006, 1);
class Solution {
public:
   int cnt =0;

    void sieve(ll n)
    {
        pr[1] = 0;
        for(ll i=4; i<=n; i+=2) pr[i] = 0;
        for(ll i=3; i*i<=n; i+=2) {
            if(pr[i]) {
                for(ll j=i*i; j<=n; j+=i) pr[j]=0;
            }
        }
        for(ll i=1; i<=n; i++) if(pr[i]) cnt++;;
    }
    
    int countPrimes(int n) {
 cnt =0;       sieve(n-1);
        
        return cnt;
        
   
    }
};