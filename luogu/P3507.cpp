#include <bits/stdc++.h>
using namespace std;
int n,a[1000005],f[1000005];
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) f[i]=max(f[i-1],a[i]-f[i-1]);
    printf("%d",f[n]);
}
