#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,m,p[105];
struct obj{int k,c;}a[105];
inline bool cmp(const obj &x,const obj &y){return x.c<y.c;}
signed main(){
    scanf("%I64d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d%I64d",&a[i].k,&a[i].c);
    sort(a+1,a+1+n,cmp);
    scanf("%I64d",&m);
    for(int i=1;i<=m;i++)
        scanf("%I64d",&p[i]);
    p[m+1]=0x7fffffffffff;
    int pt=0,f=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i].k;){
            int how=min(a[i].k-j+1,p[f]-pt);
            ans+=f*a[i].c*how;
            pt+=how;
            while(pt>=p[f]&&f<=m) f++;
            j+=how;
        }
    }
    printf("%I64d",ans);
}
