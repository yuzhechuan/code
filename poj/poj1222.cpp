#include <iostream>
#include <cstdio>
using namespace std;
const int px[5]={0,-1,1,0,0},py[5]={0,0,0,-1,1};
int T;
bool a[35][35];
signed main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        printf("PUZZLE #%d\n",t);
        for(int i=1;i<=5;i++)
            for(int j=1;j<=6;j++)
                for(int k=0;k<=4;k++){
                    int nx=i+px[k],ny=j+py[k];
                    if(nx>=1&&ny>=1&&nx<=5&&ny<=6) a[i*6+j-6][nx*6+ny-6]=1;
                }
        for(int i=1;i<=30;i++) scanf("%d",&a[i][31]);
        for(int i=1;i<=30;i++){
            int pt=i;
            while(!a[pt][i]&&pt<=30) pt++;
            for(int j=1;j<=31;j++) swap(a[i][j],a[pt][j]);
            for(int j=1;j<=30;j++){
                if(i!=j&&a[j][i])
                    for(int k=1;k<=31;k++)
                        a[j][k]=a[i][k]^a[j][k];
            }
        }
        for(int i=1;i<=30;i++)
            printf("%d%c",a[i][31],i%6?' ':'\n');
    }
}
