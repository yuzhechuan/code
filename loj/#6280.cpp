#include <bits/stdc++.h>
#define int long long
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
const int N=50005,B=333;
int L[B],R[B],block[N],a[N],n,sum[B],len,bn,tag[B];
inline void add(int l,int r,int c){
    int p=block[l],q=block[r];
    if(p==q){
        for(int i=l;i<=r;i++)
            a[i]+=c;
        sum[p]+=c*(r-l+1);
        return ;
    }
    for(int i=l;i<=R[p];i++)
        a[i]+=c;
    sum[p]+=c*(R[p]-l+1);
    for(int i=L[q];i<=r;i++)
        a[i]+=c;
    sum[q]+=c*(r-L[q]+1);
    for(int i=p+1;i<=q-1;i++)
        sum[i]+=c*(R[i]-L[i]+1),tag[i]+=c;
}
inline int que(int l,int r,int c){
    int p=block[l],q=block[r],res=0;
    if(p==q){
        for(int i=l;i<=r;i++)
            (res+=a[i]%c)%=c;
        (res+=tag[p]*(r-l+1))%=c;
        return res;
    }
    for(int i=l;i<=R[p];i++)
        (res+=a[i]%c)%=c;
    (res+=tag[p]*(R[p]-l+1))%=c;
    for(int i=L[q];i<=r;i++)
        (res+=a[i]%c)%=c;
    (res+=tag[q]*(r-L[q]+1))%=c;
    for(int i=p+1;i<=q-1;i++)
        (res+=sum[i]%c)%=c;
    return res;
}
signed main(){
    read(n);
    for(int i=1;i<=n;i++)
        read(a[i]);
    len=bn=sqrt(n);
    for(int i=1;i<=bn;i++){
        L[i]=(i-1)*len+1;
        R[i]=len*i;
    }
    if(R[bn]<n){
        L[++bn]=R[bn-1]+1;
        R[bn]=n;
    }
    for(int i=1;i<=bn;i++)
        for(int j=L[i];j<=R[i];j++){
            block[j]=i;
            sum[i]+=a[j];
        }
    for(int i=1;i<=n;i++){
        int opt,l,r,c;
        read(opt),read(l),read(r),read(c);
        if(!opt){
            add(l,r,c);
        }
        else{
            Write(que(l,r,c+1),'\n');
        }
    }
}
