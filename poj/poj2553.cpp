#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int N=5005,M=N*N>>1;
int h[N],en,n,m,dfn[N],out[N],bel[N],low[N],num,cnt;
stack<int> st;
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
struct edge{int n,u,v;}e[M];
inline void add(const int &x,const int &y){e[++en]=(edge){h[x],x,y},h[x]=en;}
inline void tarjan(int x){
    st.push(x);
    dfn[x]=low[x]=++num;
    for(int i=h[x];i;i=e[i].n){
        int y=e[i].v;
        if(!dfn[y]){
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(!bel[y])
            low[x]=min(low[x],dfn[y]);
    }
    if(low[x]==dfn[x]){
        cnt++;
        int TOP;
        do{
            TOP=st.top();
            st.pop();
            bel[TOP]=cnt;
        }while(TOP!=x);
    }
}
signed main(){
    read(n);
    while(n){
        en=num=cnt=0;
        memset(h,0,sizeof h);
        memset(dfn,0,sizeof dfn);
        memset(out,0,sizeof out);
        memset(bel,0,sizeof bel);
        memset(low,0,sizeof low);
        read(m);
        while(m--){
            int x,y;
            read(x),read(y);
            add(x,y);
        }
        for(int i=1;i<=n;i++) if(!dfn[i])
            tarjan(i);
        for(int i=1,u,v;i<=en;i++){
            u=e[i].u,v=e[i].v;
            if(bel[u]!=bel[v]) out[bel[u]]++;
        }
        for(int i=1;i<=n;i++) if(!out[bel[i]])
            Write(i,' ');
        printf("\n");
        read(n);
    }
}
