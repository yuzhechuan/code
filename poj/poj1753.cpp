//未完成
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int px[5]={0,-1,1,0,0},py[5]={0,0,0,-1,1};
int n=4,a[20][20],ans1,ans2,sol[20];
char c[20];
inline int f(const int &x,const int &y){return x*n+y-n;}
signed main(){
    for(int i=1;i<=n*n;i++){
        char cc=getchar();
        while(cc!='b'&&cc!='w') cc=getchar();
        c[i]=cc;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<=4;k++){
                int nx=i+px[k],ny=j+py[k];
                if(nx>=1&&ny>=1&&nx<=n&&ny<=n) a[f(i,j)][f(nx,ny)]=1;
            }
    for(int i=1;i<=n*n;i++)
        a[i][n*n+1]=(c[i]=='b');
    bool hhh=0;
    for(int i=1;i<=n*n;i++){
        int pt=i;
        while(!a[pt][i]&&pt<=n*n) pt++;
        swap(a[i],a[pt]);
        for(int j=1;j<=n*n;j++){
            bool flag=0;
            if(i!=j&&a[j][i])
                for(int k=1;k<=n*n+1;k++)
                    a[j][k]=a[i][k]^a[j][k];
            for(int k=1;!flag&&k<=n*n;k++) flag|=a[j][k];
            if(!flag&&a[j][n*n+1]){
                hhh=1;
                break;
            }
            if(hhh) break;
        }
        if(hhh) break;
    }
    if(hhh) ans1=0x3f3f3f3f;
    else{
        sol[n*n]=ans1=a[n*n][n*n+1];
        for(int i=n*n-1;i>=1;i--){
            sol[i]=a[i][n*n+1];
            int tp;
            for(int j=i+1;j<=n*n;j++)
                tp^=a[i][j]*sol[j];
            if(a[i][n*n+1]) sol[i]=1-tp;
            else sol[i]=tp;
            ans1+=sol[i];
        }
        // for(int i=1;i<=n*n;i++) printf("%d ",sol[i]);puts("");
    }
    memset(a,0,sizeof a);
    memset(sol,0,sizeof sol);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<=4;k++){
                int nx=i+px[k],ny=j+py[k];
                if(nx>=1&&ny>=1&&nx<=n&&ny<=n) a[f(i,j)][f(nx,ny)]=1;
            }
    for(int i=1;i<=n*n;i++)
        a[i][n*n+1]=(c[i]=='w');
    hhh=0;
    for(int i=1;i<=n*n;i++){
        int pt=i;
        while(!a[pt][i]&&pt<=n*n) pt++;
        swap(a[i],a[pt]);
        for(int j=1;j<=n*n;j++){
            bool flag=0;
            if(i!=j&&a[j][i])
                for(int k=1;k<=n*n+1;k++)
                    a[j][k]=a[i][k]^a[j][k];
            for(int k=1;!flag&&k<=n*n;k++) flag|=a[j][k];
            if(!flag&&a[j][n*n+1]){
                hhh=1;
                break;
            }
            if(hhh) break;
        }
        if(hhh) break;
    }
    if(hhh) ans2=0x3f3f3f3f;
    else{
        sol[n*n]=ans2=a[n*n][n*n+1];
        for(int i=n*n-1;i>=1;i--){
            sol[i]=a[i][n*n+1];
            int tp;
            for(int j=i+1;j<=n*n;j++)
                tp^=a[i][j]*sol[j];
            if(a[i][n*n+1]) sol[i]=1-tp;
            else sol[i]=tp;
            ans2+=sol[i];
        }
        // for(int i=1;i<=n*n;i++) printf("%d ",sol[i]);puts("");
    }
    // printf("%d %d",ans1,ans2);return 0;
    int ans=min(ans1,ans2);
    if(ans==0x3f3f3f3f) puts("Impossible");
    else printf("%d\n",ans);
}
