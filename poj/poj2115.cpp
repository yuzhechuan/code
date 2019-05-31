#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
inline ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0) {x=1,y=0;return a;}
    ll r=exgcd(b,a%b,x,y),t=x;
    x=y;
    y=t-(a/b)*y;
    return r;
}
ll A,B,C,k,x,y;
signed main(){
    while(~scanf("%lld%lld%lld%lld",&A,&B,&C,&k)){
        if(!A&&!B&&!C&&!k) break;
        ll a=C,b=(B-A),n=1ll<<k,d=exgcd(a,n,x,y);
        if(b%d) puts("FOREVER");
        else{
            x=x*(b/d)%n+n;
            printf("%lld\n",x%(n/d));
        }
    }
}
