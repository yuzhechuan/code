#include <bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],c[N];
inline int lbit(const int &x){return x&-x;}
inline void up(int i,const int &x){while(i<=n) c[i]+=x,i+=lbit(i);}
inline int que(int i){
    int tot=0;
    while(i>0){
        tot+=c[i];
        i-=lbit(i);
    }
    return tot;
}
signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),up(i,a[i]-a[i-1]);
    while(m--){
        int x,y,z,p;
        scanf("%d%d",&x,&y);
        if(x&1) scanf("%d%d",&z,&p),up(y,p),up(z+1,-p);
        else printf("%d\n",que(y));
    }
}
