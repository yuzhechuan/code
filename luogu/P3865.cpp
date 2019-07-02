#include <bits/stdc++.h>
using namespace std;
int a[100001],f[100001][20],n,m;
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
                f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int main(){
    read(n),read(m);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) f[i][0]=a[i];
    rmq(n);
    while(m--){
        int x,y;
        read(x),read(y);
        int k=log2(1.0*(y-x+1));
        printf("%d\n",max(f[x][k],f[y-(1<<k)+1][k]));
    }
}
