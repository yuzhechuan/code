#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=N<<1;
struct edge{
    int v,n,w;
}e[M];
int en,h[N],d[N],n,m;
inline void read(int &x){
    x=0;char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
inline void add(const int &x,const int &y,const int &z){e[++en].n=h[x];e[en].w=z;e[en].v=y;h[x]=en;}
void dfs(int x,int fa,int val){
    d[x]=val;
    for(int i=h[x];i;i=e[i].n){
        int y=e[i].v;
        if(y==fa) continue;
        dfs(y,x,val^e[i].w);
    }
}
signed main(){
    read(n);
    for(int i=1;i<=n-1;i++){
        int x,y,z;
        read(x),read(y),read(z);
        add(x,y,z),add(y,x,z);
    }
    dfs(1,0,0);
    read(m);
    while(m--){
        int x,y;
        read(x),read(y);
        printf("%d\n",d[x]^d[y]);
    }
}
