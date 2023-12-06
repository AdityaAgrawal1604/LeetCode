class Solution {
public:
    int totalMoney(int n) {
        int i = 1;
        int ans = 0;
        int mod = n%7;
int k = 1;
        while(n--){
            ans+=i;
            i++;
            if((n%7)==mod) {
                k++;
                i = k;
            }
        }
        return ans;
    }
};