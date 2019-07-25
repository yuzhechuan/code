#include <bits/stdc++.h>
using namespace std;
const int dx[8]={-1,1,-1,1,2,-2,2,-2},dy[8]={2,2,-2,-2,-1,-1,1,1};
const int goal[6][6]={
{0,0,0,0,0,0},
{0,1,1,1,1,1},
{0,0,1,1,1,1},
{0,0,0,-1,1,1},
{0,0,0,0,0,1},
{0,0,0,0,0,0}
};
inline void swap(int &x,int &y){x^=y^=x^=y;}
int t,ans,a[6][6],sx,sy;
inline int rd(){
    char c=getchar();
    while(!isdigit(c)&&c!='*') c=getchar();
    if(isdigit(c)) return c-'0';
    return -1;
}
inline int gj(){
    int res=0;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)if(goal[i][j]^a[i][j])
            res++;
    return res;
}
void dfs(int x,int y,int z){
    // printf("%d %d %d\n",x,y,z);
    // for(int i=1;i<=5;i++,puts(""))
        // for(int j=1;j<=5;j++) printf("%d ",a[i][j]);
    int g=gj();
    if(g+z>ans) return ;
    if(!g){
        ans=min(ans,z);
        return ;
    }
    for(int i=0;i<8;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&ny>0&&nx<=5&&ny<=5){
            swap(a[x][y],a[nx][ny]);
            dfs(nx,ny,z+1);
            swap(a[x][y],a[nx][ny]);
        }
    }
}
signed main(){
    scanf("%d",&t);
    while(t--){
        ans=16;
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++){
                a[i][j]=rd();
                if(a[i][j]==-1){
                    sx=i,sy=j;
                }
            }
        dfs(sx,sy,0);
        printf("%d\n",ans<16?ans:-1);
    }
}
