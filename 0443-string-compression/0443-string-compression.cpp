class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0;
        int j = 1;
        int cnt = 1;
        while(j<n){
            if(chars[j]==chars[i]){
                cnt++;
                j++;
            }else{
                if(cnt==1){
                    i = j;
                    j++;
                    continue;
                }
                if(cnt<10){
                    i++;
                    chars[i] = (char)(cnt+'0');

                }else{
                    i++;
                    string x = "";
                    while(cnt){
                        x+=(char(cnt%10+'0'));
                        cnt/=10;
                    }
                    reverse(x.begin(),x.end());
                    for(auto p:x){
                        chars[i]=p;
                        i++;
                    }
                    i--;
                }
                i++;
                int i1 = i;
                while(j<n){
                    chars[i] = chars[j];
                    i++;
                    j++;
                }
                for(int k = i;k<j;k++){
                    chars.pop_back();
                }
                n = chars.size();
                i--;
                // while(!(((int)(chars[i])>=(int)('0'))&&((int)(chars[i])<=(int)(9+'0')))){
                //     i--;
                // }
                i = i1;
                cnt = 1;
                // i++;
                j = i+1;
            }
        }
        if(cnt>1){
            if(cnt<10){
                i++;
                chars[i] = (char)(cnt+'0');
                i++;
            }else{
                i++;
                string x = "";
                while(cnt){
                    x+=(char(cnt%10+'0'));
                    cnt/=10;
                }
                reverse(x.begin(),x.end());
                for(auto p:x){
                    chars[i]=p;
                    i++;
                }
            }
            for(int k = i;k<j;k++){
                chars.pop_back();
            }
            
        }
        n = chars.size();
        return n;
    }
};