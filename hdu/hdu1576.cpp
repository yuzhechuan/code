#include <bits/stdc++.h>
using namespace std;
const int k=9973;
int n,b,x,y;
inline void exgcd(const int &a,const int &b,int &x,int &y){
    if(!b) x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
signed main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&b);
        exgcd(b,k,x,y);
        x=(x%k+k)%k;
        printf("%d\n",(x*n)%k);
    }
}
