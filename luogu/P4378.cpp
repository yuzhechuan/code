#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N],b[N],c[N],ans;
inline int fyc(const int &x){return x&-x;}
inline void up(int i){while(i<=n) c[i]++,i+=fyc(i);}
inline int que(int i){
    int tot=0;
    while(i>0) tot+=c[i],i-=fyc(i);
    return tot;
}
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    int cur=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++){
        int x=lower_bound(b+1,b+cur+1,a[i])-b;
        up(x);
        ans=max(ans,i-que(x));
    }
    printf("%d",ans+1);
}
