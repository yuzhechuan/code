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
const int N=50050,B=250;
int a[N],L[B],R[B],block[N],sum[B],n,bn,len;
bool v[B];
inline void upd(const int &x){
    v[x]=1;
    for(rint i=L[x];i<=R[x];i++){
        int now=sqrt(a[i]);
        sum[x]-=a[i]-now;
        a[i]=now;
        if(a[i]>1) v[x]=0;
    }
}
inline void edi(int l,int r){
    int p=block[l],q=block[r];
    if(p==q){
        if(!v[p]){
            for(rint i=l;i<=r;i++){
                int now=sqrt(a[i]);
                sum[p]-=a[i]-now;
                a[i]=now;
            }
        }
        return ;
    }
    for(rint i=p+1;i<=q-1;i++) if(!v[i])
        upd(i);
    if(!v[p])
    for(rint i=l;i<=R[p];i++){
        int now=sqrt(a[i]);
        sum[p]-=a[i]-now;
        a[i]=now;
    }
    if(!v[q])
    for(rint i=L[q];i<=r;i++){
        int now=sqrt(a[i]);
        sum[q]-=a[i]-now;
        a[i]=now;
    }
}
inline int que(int l,int r){
    int p=block[l],q=block[r],res=0;
    if(p==q){
        for(rint i=l;i<=r;i++)
            res+=a[i];
        return res;
    }
    for(rint i=p+1;i<=q-1;i++)
        res+=sum[i];
    for(rint i=l;i<=R[p];i++)
        res+=a[i];
    for(rint i=L[q];i<=r;i++)
        res+=a[i];
    return res;
}
signed main(){
    read(n);
    for(rint i=1;i<=n;i++)
        read(a[i]);
    bn=len=sqrt(n);
    for(rint i=1;i<=bn;i++){
        L[i]=(i-1)*len+1;
        R[i]=i*len;
    }
    if(R[bn]<n){
        L[++bn]=R[bn-1]+1;
        R[bn]=n;
    }
    for(rint i=1;i<=bn;i++)
        for(rint j=L[i];j<=R[i];j++){
            block[j]=i;
            sum[i]+=a[j];
        }
    while(n--){
        int opt,l,r,c;
        read(opt),read(l),read(r),read(c);
        if(!opt){
            edi(l,r);
        }
        else{
            Write(que(l,r),'\n');
        }
    }
}
