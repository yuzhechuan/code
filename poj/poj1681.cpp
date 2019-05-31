#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int px[5]={0,-1,1,0,0},py[5]={0,0,0,-1,1};
int t,n,a[230][230];
inline int f(const int &x,const int &y){return x*n+y-n;}
signed main(){
    scanf("%d",&t);
    while(t--){
    	memset(a,0,sizeof a);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=0;k<=4;k++){
                    int nx=i+px[k],ny=j+py[k];
                    if(nx>=1&&ny>=1&&nx<=n&&ny<=n) a[f(i,j)][f(nx,ny)]=1;
                }
        for(int i=1;i<=n*n;i++){
            char c=getchar();
            while(c!='y'&&c!='w') c=getchar();
            a[i][n*n+1]=(c=='w');
        }
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
                    puts("inf");
                    hhh=1;
                    break;
                }
                if(hhh) break;
            }
            if(hhh) break;
        }
        if(hhh) continue;
        int ans=0;
        for(int i=1;i<=n*n;i++)
            ans+=a[i][n*n+1];
        printf("%d\n",ans);
    }
}
