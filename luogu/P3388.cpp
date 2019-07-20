#include <bits/stdc++.h>
using namespace std;
template<class t> void read(t &x){
    x=0;char c=getchar();
    bool f=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;
}
template<class t> void write(t x){
    if(x<0) putchar('-'),write(-x);
    else{
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
template<class t> void Write(t x,char c){
    write(x);putchar(c);
}
const int N=2e4+5,M=2e5+5;
int n,m,h[N],en,dfn[N],low[N],num,un;
bool is[N];
struct edge{int n,v;}e[M];
inline void add(const int &x,const int &y){e[++en]=(edge){h[x],y};h[x]=en;}
inline void tarjan(int x,int fa){
    dfn[x]=low[x]=++num;
    int son=0;
    for(int i=h[x];i;i=e[i].n){
        int y=e[i].v;
        if(!dfn[y]){
            tarjan(y,fa);
            low[x]=min(low[x],low[y]);
            if(low[y]>=dfn[x]&&x!=fa)
                is[x]=1;
            if(x==fa) son++;
        }
        low[x]=min(low[x],dfn[y]);
    }
    if(son>=2&&x!=fa) is[x]=1;
}
signed main(){
    read(n);
    read(m);
    for(int i=1,x,y;i<=m;i++){
        read(x);
        read(y);
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++) if(!dfn[i])
        tarjan(i,i);
    for(int i=1;i<=n;i++) if(is[i])
        un++;
    Write(un,'\n');
    for(int i=1;i<=n;i++) if(is[i])
        Write(i,' ');
}
