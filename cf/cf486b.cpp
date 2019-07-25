#include <bits/stdc++.h>
using namespace std;
int n,m,a[105][105],b[105][105],h[105],z[105],ah[105],az[105];
signed main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&b[i][j]);
            if(b[i][j]) continue;
            if(!z[j])for(int k=1;k<=n;k++) a[k][j]=0;
            if(!h[i])for(int k=1;k<=m;k++) a[i][k]=0;
            h[i]=z[j]=1;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            ah[i]|=a[i][j];
            az[j]|=a[i][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) if(b[i][j]^(ah[i]|az[j])){
            puts("NO");
            return 0;
        }
    puts("YES");
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++)
            printf("%d ",a[i][j]);
}
