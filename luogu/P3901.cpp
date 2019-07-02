#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],f[N][20],b[N],n,m;
inline void read(int &x){
    x=0;bool f=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=1;c=getchar();}
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;
}
void rmq(const int &n){
    int lg=log2(n);
    for(int j=1;j<=lg;j++)
        for(int i=1;i<=n;i++)
            if(i+(1<<j)-1<=n)
                f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
inline int que(const int &x,const int &y){
    int k=log2(1.0*(y-x+1));
    return max(f[x][k],f[y-(1<<k)+1][k]);
}
int main(){
    read(n),read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) f[i][0]=b[a[i]],b[a[i]]=i;
    rmq(n);
    while(m--){
        int x,y;
        read(x),read(y);
        if(que(x,y)>=x) puts("No");
        else puts("Yes");
    }
}
