#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,k,p,col,pri,lt[N],sum[N],a[N],now,ans;
signed main(){
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&col,&pri);
        if(pri<=p) now=i;
        if(now>=lt[col]) sum[col]=a[col];
        lt[col]=i;
        ans+=sum[col];
        a[col]++;
    }
    printf("%d",ans);
}
