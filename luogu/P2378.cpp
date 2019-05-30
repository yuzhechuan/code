#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
int a=1,b,c,i,delta,x1,x2;
short f;
char s[150];
char fyc(int x){
    if(x<0) return '+';
    return '-';
}
signed main(){
    scanf("%s",s+1);
    if(strlen(s+1)==3){
        printf("%s",s+1);
        return 0;
    }
    if(s[2]=='^'){
        if(s[4]=='-') f=-1;else f=1;
        for(i=5;isdigit(s[i]);i++) b=(b<<1)+(b<<3)+(s[i]^48);
        b=max(b,1ll);
        b*=f;
        if(s[i]!='x') c=b,b=0;
        else{
            i++;
            if(s[i]=='-') f=-1;else f=1;
            for(i++;s[i];i++) c=(c<<1)+(c<<3)+(s[i]^48);
            c*=f;
        }
    }
    else{
        printf("%s",s+1);
        return 0;
    }
    delta=b*b-4*a*c;
    x2=(-b+sqrt(delta))/(2*a);
    x1=(-b-sqrt(delta))/(2*a);
    if(x1==0) putchar('x');
    else printf("(x%c%lld)",fyc(x1),abs(x1));
    if(x1==x2) puts("^2");
    else if(x2==0) putchar('x');
    else printf("(x%c%lld)",fyc(x2),abs(x2));
}
