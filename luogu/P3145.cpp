#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=50005;
int f[N][20],g[N][20],n,m,t[N],l,r,before,after=0x7ffffffffffffff;
struct point{
    int x,y;
}a[N];
inline void read(int &x){
    x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
void rmq(const int &n){
    int lg=log2(n);
    for(int j=1;j<=lg;j++)
        for(int i=1;i<=n;i++) if(i+(1<<j)-1<=n)
                f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]),
                g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
}
inline bool cmpx(const point &x,const point &y){if(x.x==y.x) return x.y<y.y;return x.x<y.x;}
inline bool cmpy(const point &x,const point &y){if(x.y==y.y) return x.x<y.x;return x.y<y.y;}
inline int que(const int &x,const int &y){
    int k=log2(1.0*(y-x+1));
    int big=max(f[x][k],f[y-(1<<k)+1][k]),small=min(g[x][k],g[y-(1<<k)+1][k]);
    return big-small;
}
signed main(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i].x),read(a[i].y);
////////////////////////////////////////////////////////
    memset(g,128,sizeof g);
    memset(f,0,sizeof f);
    m=0;
    sort(a+1,a+1+n,cmpx);
    before=a[n].x-a[1].x;
    l=1;
    while(l<=n){
        r=l;
        while(a[r].x==a[r+1].x) r++;
        t[++m]=a[r].x;
        f[m][0]=a[r].y;
        g[m][0]=a[l].y;
        l=r+1;
    }
    rmq(m);
    for(int i=1;i<m;i++){
        int x=(t[i]-t[1])*que(1,i),
            y=(t[m]-t[i+1])*que(i+1,m);
        after=min(after,x+y);
    }
////////////////////////////////////////////////////////
    memset(g,128,sizeof g);
    memset(f,0,sizeof f);
    memset(t,0,sizeof t);
    m=0;
    sort(a+1,a+1+n,cmpy);
    before*=a[n].y-a[1].y;
    l=1;
    while(l<=n){
        r=l;
        while(a[r].y==a[r+1].y) r++;
        t[++m]=a[r].y;
        f[m][0]=a[r].x;
        g[m][0]=a[l].x;
        l=r+1;
    }
    rmq(m);
    for(int i=1;i<m;i++){
        int x=(t[i]-t[1])*que(1,i),
            y=(t[m]-t[i+1])*que(i+1,m);
        after=min(after,x+y);
    }
////////////////////////////////////////////////////////
    printf("%lld",before-after);
}
