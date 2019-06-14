#include <bits/stdc++.h>
using namespace std;
class BinaryCode{
public:
    vector<string> decode(string s){
        vector<string> ans;
        int a[55];
        ostringstream tp;
        bool flag=1;
            string k1,k2;
        memset(a,0,sizeof a);
        for(int i=1;i<=s.length();i++){
            if((a[i]+a[i-1]+1<s[i-1]-'0')||(a[i]+a[i-1]>s[i-1]-'0')){
                flag=0;
                // printf("|||%d %d %d %d %d\n",(a[i]+a[i-1]+1<s[i-1]-'0'),(a[i]+a[i-1]>s[i-1]-'0'),a[i]+a[i-1],i,s[i-1]^48);
                break;
            }
            tp<<a[i];
            a[i+1]=(s[i-1]^48)-a[i]-a[i-1];
        }
        if(!flag) ans.push_back("NONE"),k1="NONE";
        else ans.push_back(tp.str()),k1=tp.str();

        tp.clear();
        flag=1;
        memset(a,0,sizeof a);
        a[1]=1;
        for(int i=1;i<=s.length();i++){
            if((a[i]+a[i-1]+1<s[i-1]-'0')||(a[i]+a[i-1]>s[i-1]-'0')){
                flag=0;
                // printf("|||%d\n",i);
                break;
            }
            tp<<a[i];
            a[i+1]=(s[i-1]^48)-a[i]-a[i-1];
        }
        if(!flag) ans.push_back("NONE"),k2="NONE";
        else ans.push_back(tp.str()),k2=tp.str();
        cout<<k1<<" "<<k2;
        return ans;
    }
}a;
signed main(){
    a.decode("123210122");
    // a.decode("22111");
}
