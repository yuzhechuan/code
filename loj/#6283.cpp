#include <bits/stdc++.h>
#define rint register int
using namespace std;
#define getchar gc
char getchar(){
	static char buf[1<<16],*p1=buf,*p2=buf;
	if(p1==p2){
		p2=(p1=buf)+fread(buf,1,1<<16,stdin);
		if(p2==p1) return EOF;
	}
	return *p1++;
}
template<class t> void read(t &x){
    x=0;char c=getchar();
    bool f=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;
}
template<class t> void write(t x){
    if(x<0) putchar('-'),write(-x);
    else{
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
template<class t> void Write(t x,char c){
	write(x);putchar(c);
}
const int mod=1e4+7,N=1e5+20,B=335;
int n,a[N],block[N],L[B],R[B],mul[B],add[B],bn,len;
inline void push(const int &x){
    for(rint i=L[x];i<=R[x];i++)
        a[i]=(a[i]*mul[x]%mod+add[x])%mod;
    mul[x]=1;
    add[x]=0;
}
inline void edi(bool flag,int l,int r,int v){
    int p=block[l],q=block[r];
    push(p);
    if(p==q){
        for(rint i=l;i<=r;i++)
            a[i]=flag?(a[i]*v)%mod:(a[i]+v)%mod;
        return ;
    }
    push(q);
    for(rint i=p+1;i<=q-1;i++){
        if(flag){
            (mul[i]*=v)%=mod;
            (add[i]*=v)%=mod;
        }
        else{
            (add[i]+=v)%=mod;
        }
    }
    for(rint i=l;i<=R[p];i++)
        a[i]=flag?(a[i]*v)%mod:(a[i]+v)%mod;
    for(rint i=L[q];i<=r;i++)
        a[i]=flag?(a[i]*v)%mod:(a[i]+v)%mod;
}
signed main(){
    read(n);
    for(rint i=1;i<=n;i++)
        read(a[i]),a[i]%=mod;
    bn=len=sqrt(n);
    for(rint i=1;i<=bn;i++){
        L[i]=(i-1)*len+1;
        R[i]=i*len;
    }
    if(R[bn]<n){
        L[++bn]=R[bn-1]+1;
        R[bn]=n;
    }
    for(rint i=1;i<=bn;i++){
        mul[i]=1;
        for(rint j=L[i];j<=R[i];j++)
            block[j]=i;
    }
    while(n--){
        int opt,l,r,c;
        read(opt),read(l),read(r),read(c);
        if(opt<=1){
            edi(opt,l,r,c);
        }
        else{
            c=block[r];
            Write((a[r]*mul[c]%mod+add[c])%mod,'\n');
        }
    }
}
