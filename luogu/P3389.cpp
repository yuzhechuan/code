#include <bits/stdc++.h>
using namespace std;
const double eps=1e-9;
int n;
double a[105][105],sol[105];
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n+1;j++)
            scanf("%lf",&a[i][j]);
    for(int i=1;i<=n;i++){
        int pt=i;
        for(int j=i+1;j<=n;j++)
            if(fabs(a[j][i])>fabs(a[pt][i])) pt=j;
        if(fabs(a[pt][i])<eps){
            puts("No Solution");
            return 0;
        }
        if(i!=pt) swap(a[i],a[pt]);
        double tp=a[i][i];
        for(int j=i;j<=n+1;j++)
            a[i][j]/=tp;
        for(int j=i+1;j<=n;j++){
            tp=a[j][i];
            for(int k=i;k<=n+1;k++)
                a[j][k]-=a[i][k]*tp;
        }
    }
    sol[n]=a[n][n+1];
    for(int i=n-1;i>=1;i--){
        sol[i]=a[i][n+1];
        for(int j=i+1;j<=n;j++)
            sol[i]-=a[i][j]*sol[j];
    }
    for(int i=1;i<=n;i++)
        printf("%.2lf\n",sol[i]);
}
