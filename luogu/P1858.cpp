#include <bits/stdc++.h>
using namespace std;
int f[5010][55],ans,k,v,n,w[205],c[205],t[55];
signed main(){
    memset(f,-66,sizeof f);
    scanf("%d%d%d",&k,&v,&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&c[i]);
    f[0][1]=0;
    for(int i=1;i<=n;i++)
        for(int j=v;j>=w[i];j--){
            int p1=1,p2=1,z[k+5],m=0;
            while(p1+p2<=k+1)
                if(f[j][p1]>f[j-w[i]][p2]+c[i]) z[++m]=f[j][p1++];
                else z[++m]=f[j-w[i]][p2++]+c[i];
            for(int kk=1;kk<=k;kk++) f[j][kk]=z[kk];
        }
    for(int i=1;i<=k;i++) ans+=f[v][i];
    printf("%d",ans);
}
