#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
ll n,m,s,t,a[N],b[N],ans;
inline ll fyc(const ll &x){return x>0?-x*s:-x*t;}
signed main(){
    scanf("%lld%lld%lld%lld\n0",&n,&m,&s,&t);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        b[i]=a[i]-a[i-1];
        ans+=fyc(b[i]);
    }
    while(m--){
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        ans-=fyc(b[x]);
        b[x]+=z;
        ans+=fyc(b[x]);
        if(y<n){
            ans-=fyc(b[y+1]);
            b[y+1]-=z;
            ans+=fyc(b[y+1]);
        }
        printf("%lld\n",ans);
    }
}
