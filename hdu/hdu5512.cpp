#include <bits/stdc++.h>
using namespace std;
int a,b,n,t;
inline int gcd(const int &a,const int &b){return b?gcd(b,a%b):a;};
signed main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d",&n,&a,&b);
        printf("Case #%d: ",i);
        if(n/gcd(a,b)&1) puts("Yuwgna");
        else puts("Iaka");
    }
}
