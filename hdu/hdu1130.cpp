#include <bits/stdc++.h>
using namespace std;
struct num{
    int n,a[105];
    void clear(){n=0;memset(a,0,sizeof(a));}
    void work(){while(n>1&&!a[n]) n--;}
    num write(){
        for(int i=n;i;i--)
            putchar('0'+a[i]);
        return *this;
    }
    num operator = (const int &nt){
        n=0;
        int x=nt;
        while(x){
            a[++n]=x%10;
            x/=10;
        }
        return *this;
    }
    num operator + (const num &nt){
        num tp;
        tp.clear();
        tp.n=max(n,nt.n)+1;
        for(int i=1;i<=tp.n;i++){
            tp.a[i]+=a[i]+nt.a[i];
            tp.a[i+1]+=tp.a[i]/10;
            tp.a[i]%=10;
        }
        tp.work();
        return tp;
    }
    num operator * (const num &nt){
        num tp;
        tp.clear();
        tp.n=n+nt.n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=nt.n;j++)
                tp.a[i+j-1]+=a[i]*nt.a[j];
        for(int i=1;i<=tp.n;i++){
            tp.a[i+1]+=tp.a[i]/10;
            tp.a[i]%=10;
        }
        tp.work();
        return tp;
    }
}f[105];
int x;
signed main(){
    f[0]=1;
    for(int i=1;i<=101;i++)
        for(int j=0;j<=i-1;j++)
            f[i]=f[i]+f[j]*f[i-j-1];
    while(~scanf("%d",&x)){
        f[x].write();
        puts("");
    }
}
