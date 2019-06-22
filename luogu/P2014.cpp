#include <bits/stdc++.h>
using namespace std;
struct edge{
    int n,y,z;
}e[305];
int f[305][355],h[305],en,n,m;
inline void add(const int &x,const int &y,const int &z){
    e[++en].y=y;e[en].z=z;
    e[en].n=h[x];h[x]=en;
}
inline void dp(const int &x,const int &fa){
    for(int k=h[x];k!=-1;k=e[k].n){
        int y=e[k].y;
        if(y!=fa) dp(y,x);
        else continue;
        for(int i=m;i>=0;i--)
            for(int j=i;j>=1;j--)
                f[x][i]=max(f[x][i],f[x][i-j]+f[y][j-1]+e[k].z);
    }
}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,i,y);
    }
    dp(0,-1);
    printf("%d",f[0][m]);
}
