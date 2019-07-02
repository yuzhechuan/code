#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int ans,a[50][N],b[50],g[N][20],n,m,p;
inline void read(int &x){
    x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
void rmq(int n){
    int lg=log2(n);
    for(int j=1;j<=lg;j++)
        for(int i=1;i<=n;i++)
            if(i+(1<<j)-1<=n)
                g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
}
inline int que(const int &x,const int &y){
    int k=log2(1.0*(y-x+1));
    int small=min(g[x][k],g[y-(1<<k)+1][k]);
    return small;
}
signed main(){
    memset(g,66,sizeof g);
    read(n),read(m),read(p);
    for(int i=1,x;i<=n;i++){
        read(x);
        a[x][++b[x]]=i;
        read(g[i][0]);
    }
    rmq(n);
    for(int i=0;i<m;i++)
        for(int j=1;j<b[i];j++)
            for(int k=j+1;k<=b[i];k++){
                if(que(a[i][j],a[i][k])<=p){
                    ans+=b[i]-k+1;
                    break;
                }
            }
    printf("%d",ans);
}
