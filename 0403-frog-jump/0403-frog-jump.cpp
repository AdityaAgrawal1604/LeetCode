class Solution {
public:
    int f(int i,int k,vector<int> &s,map<pair<int,int>,int> &dp){
        if(i==s.size()-1) return 1;
        if(dp.find({i,k}) != dp.end()) return dp[{i,k}];
        int fl = 0;

        int ind = lower_bound(s.begin(),s.end(),s[i]+k)-s.begin();
        if(ind!=s.size()&&s[ind]==(s[i]+k)){
            fl|=f(ind,k,s,dp);
        }
        ind = lower_bound(s.begin(),s.end(),s[i]+k+1)-s.begin();
        if(ind!=s.size()&&s[ind]==(s[i]+k+1)){
            fl|=f(ind,k+1,s,dp);
        }
        ind = lower_bound(s.begin(),s.end(),s[i]+k-1)-s.begin();
        if(ind!=s.size()&&s[ind]==(s[i]+k-1)&&k!=1){
            fl|=f(ind,k-1,s,dp);
        }
        return dp[{i,k}]=fl;
    }
    bool canCross(vector<int>& s) {
        map<pair<int,int>,int> dp;
        if(s.size()==1) return true;
        if(s[1]!=1) return false;
        return f(1,1,s,dp);
    }
};