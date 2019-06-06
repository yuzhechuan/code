#include <bits/stdc++.h>
using namespace std;
long long ans,n;
char s[1005];
signed main(){
    scanf("%lld%s",&n,s);
    for(int i=0;s[i];i++) ans=((ans<<1)+(ans<<3)+(s[i]^48))%n;
    printf("%lld",ans?ans:n);
}
