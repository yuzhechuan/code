#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int f(const int &x){
    if(x%4==1) return 1;
    if(x%4==0) return x;
    if(x%4==2) return x+1;
    return 0;
}
int n,ans;
signed main(){
    scanf("%d",&n);
    for(int i=1,x,m;i<=n;++i){
        scanf("%d%d",&x,&m);
        ans^=f(x-1)^f(x+m-1);
    }
    if(ans) puts("tolik");
    else puts("bolik");
}
