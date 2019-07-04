#include <bits/stdc++.h>
using namespace std;
const int N=105,M=N<<1;
struct edge{
    int v,n,x;
}e[M];
int en,h[N],f[N][20],dep,d[N],n,kk,kkk,a[N];
inline void read(int &x){
    x=0;char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
inline void add(const int &x,const int &y){e[++en].n=h[x];e[en].v=y;h[x]=en;}
void dfs(int x){
    for(int i=h[x];i;i=e[i].n){
        int y=e[i].v;
        if(y==f[x][0]) continue;
        d[y]=d[x]+1;
        a[d[y]]++;kkk=max(kkk,d[y]);
        f[y][0]=x;
        dfs(y);
    }
}
void prepare(){
    for(int j=1;j<=dep;j++)
        for(int i=1;i<=n;i++)
            f[i][j]=f[f[i][j-1]][j-1];
}
inline int lca(int x,int y){
    if(x==y) return x;
    if(d[x]<d[y]) swap(x,y);
    for(int i=dep;i>=0;i--)
        if(d[f[x][i]]>=d[y]&&f[x][i])
            x=f[x][i];
    if(x==y) return x;
    for(int i=dep;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}
signed main(){
    read(n);
    dep=log2(n);
    for(int i=1;i<=n-1;i++){
        int x,y;
        read(x),read(y);
        add(x,y),add(y,x);
    }
    dfs(1);
    prepare();
    printf("%d\n",kkk+1);
    for(int i=0;i<=kkk;i++) kk=max(kk,a[i]);
    printf("%d\n",kk);
    int yzc,fyc;
    read(yzc),read(fyc);
    printf("%d",2*d[yzc]+d[fyc]-3*d[lca(yzc,fyc)]);
}
