#include <iostream>
#include <cstdio>
#include <cstdlib>
#define int long long
using namespace std;
int x,y,a,b,gcd,m,n,l;
inline void exgcd(int a,int b,int &x,int &y){
    if(!b) x=1,y=0,gcd=a;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
signed main(){
    scanf("%lld%lld%lld%lld%lld",&a,&b,&m,&n,&l);
    exgcd(m-n,l,x,y);
    int k=abs(l/gcd);
    if((b-a)%gcd) puts("Impossible");
    else printf("%lld",(x*((b-a)/gcd)%k+k)%k);
}
