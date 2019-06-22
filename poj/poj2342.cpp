#include <iostream>
#include <cstdio>
using namespace std;
int en,n,h[100000],f[100000][2],a[100000];
bool v[100000];
struct edge{
    int y,n;
}e[1000001];
inline void add(const int &x,const int &y){
    e[++en].y=y;e[en].n=h[x];h[x]=en;
}
void dfs(int x){
    f[x][1]=a[x];
    for(int i=h[x];i;i=e[i].n){
        int y=e[i].y;
        dfs(y);
        f[x][1]+=f[y][0];
        f[x][0]+=max(f[y][1],f[y][0]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(y,x);
        v[x]=1;
    }
    for(int i=1;i<=n;i++) if(!v[i]){
    	add(0,i);
		break;
	}
    dfs(0);
    printf("%d",max(f[0][1],f[0][0]));
}
