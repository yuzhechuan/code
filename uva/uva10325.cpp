#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int m,rm;
ll ans,n,a[16];
inline ll gcd(const ll &x,const ll &y){
    if(!y) return x;
    return gcd(y,x%y);
}
inline void dfs(const int &x,const bool &flag,ll lcm){
    lcm=a[x]/gcd(a[x],lcm)*lcm;
    if(flag) ans+=n/lcm;
    else ans-=n/lcm;
    for(int i=x+1;i<=rm;i++) dfs(i,!flag,lcm);
}
signed main(){
     while(~scanf("%lld%d",&n,&m)){
         ans=rm=0;
         for(int i=1;i<=m;i++){
             scanf("%lld",&a[i]);
             if(a[i]) a[++rm]=a[i];
         }
         for(int i=1;i<=rm;i++) dfs(i,1,a[i]);
         printf("%lld\n",n-ans);
     }
}
